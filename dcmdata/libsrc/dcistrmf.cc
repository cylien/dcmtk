/*
 *
 *  Copyright (C) 2002-2007, OFFIS
 *
 *  This software and supporting documentation were developed by
 *
 *    Kuratorium OFFIS e.V.
 *    Healthcare Information and Communication Systems
 *    Escherweg 2
 *    D-26121 Oldenburg, Germany
 *
 *  THIS SOFTWARE IS MADE AVAILABLE,  AS IS,  AND OFFIS MAKES NO  WARRANTY
 *  REGARDING  THE  SOFTWARE,  ITS  PERFORMANCE,  ITS  MERCHANTABILITY  OR
 *  FITNESS FOR ANY PARTICULAR USE, FREEDOM FROM ANY COMPUTER DISEASES  OR
 *  ITS CONFORMITY TO ANY SPECIFICATION. THE ENTIRE RISK AS TO QUALITY AND
 *  PERFORMANCE OF THE SOFTWARE IS WITH THE USER.
 *
 *  Module:  dcmdata
 *
 *  Author:  Marco Eichelberg
 *
 *  Purpose: DcmInputFileStream and related classes,
 *    implements streamed input from files.
 *
 *  Last Update:      $Author: meichel $
 *  Update Date:      $Date: 2007-02-19 15:45:31 $
 *  CVS/RCS Revision: $Revision: 1.6 $
 *  Status:           $State: Exp $
 *
 *  CVS/RCS Log at end of file
 *
 */

#include "dcmtk/config/osconfig.h"
#include "dcmtk/dcmdata/dcistrmf.h"
#include "dcmtk/dcmdata/dcerror.h"

#define INCLUDE_CSTDIO
#define INCLUDE_CERRNO
#include "dcmtk/ofstd/ofstdinc.h"


DcmFileProducer::DcmFileProducer(const char *filename, offile_off_t offset)
: DcmProducer()
, file_()
, status_(EC_Normal)
, size_(0)
{
  if (file_.fopen(filename, "rb"))
  {
     // Get number of bytes in file
     file_.fseek(0L, SEEK_END);
     size_ =  file_.ftell();
     if (0 != file_.fseek(offset, SEEK_SET))
     {
       OFString s("(unknown error code)");
       file_.getLastErrorString(s);
       status_ = makeOFCondition(OFM_dcmdata, 18, OF_error, s.c_str());
     }
  }
  else
  {
    OFString s("(unknown error code)");
    file_.getLastErrorString(s);
    status_ = makeOFCondition(OFM_dcmdata, 18, OF_error, s.c_str());
  }
}

DcmFileProducer::~DcmFileProducer()
{
}

OFBool DcmFileProducer::good() const
{
  return status_.good();
}

OFCondition DcmFileProducer::status() const
{
  return status_;
}

OFBool DcmFileProducer::eos() 
{
  if (file_.open())
  {
    return (file_.eof() || (size_ == file_.ftell()));
  }
  else return OFTrue;
}

offile_off_t DcmFileProducer::avail()
{
  if (file_.open()) return size_ - file_.ftell(); else return 0;
}

offile_off_t DcmFileProducer::read(void *buf, offile_off_t buflen)
{
  offile_off_t result = 0;
  if (status_.good() && file_.open() && buf && buflen)
  {
    result = file_.fread(buf, 1, OFstatic_cast(size_t, buflen));
  }
  return result;
}

offile_off_t DcmFileProducer::skip(offile_off_t skiplen)
{
  offile_off_t result = 0;
  if (status_.good() && file_.open() && skiplen)
  {
    offile_off_t pos = file_.ftell();
    result = (size_ - pos < skiplen) ? (size_ - pos) : skiplen;
    if (file_.fseek(result, SEEK_CUR))
    {
      OFString s("(unknown error code)");
      file_.getLastErrorString(s);
      status_ = makeOFCondition(OFM_dcmdata, 18, OF_error, s.c_str());
    }
  }
  return result;
}

void DcmFileProducer::putback(offile_off_t num)
{
  if (status_.good() && file_.open() && num)
  {
    offile_off_t pos = file_.ftell();
    if (num <= pos)
    {
      if (file_.fseek(-num, SEEK_CUR))
      {
        OFString s("(unknown error code)");
        file_.getLastErrorString(s);
        status_ = makeOFCondition(OFM_dcmdata, 18, OF_error, s.c_str());
      }
    }
    else status_ = EC_PutbackFailed; // tried to putback before start of file
  }
}


/* ======================================================================= */

DcmInputFileStreamFactory::DcmInputFileStreamFactory(const char *filename, offile_off_t offset)
: DcmInputStreamFactory()
, filename_()
, offset_(offset)
{
  if (filename) filename_ = filename;
}

DcmInputFileStreamFactory::DcmInputFileStreamFactory(const DcmInputFileStreamFactory& arg)
: DcmInputStreamFactory(arg)
, filename_(arg.filename_)
, offset_(arg.offset_)
{
}

DcmInputFileStreamFactory::~DcmInputFileStreamFactory()
{
}

DcmInputStream *DcmInputFileStreamFactory::create() const
{
  return new DcmInputFileStream(filename_.c_str(), offset_);
}

/* ======================================================================= */

DcmInputFileStream::DcmInputFileStream(const char *filename, offile_off_t offset)
: DcmInputStream(&producer_) // safe because DcmInputStream only stores pointer
, producer_(filename, offset)
, filename_()
{
  if (filename) filename_ = filename;
}

DcmInputFileStream::~DcmInputFileStream()
{
}

DcmInputStreamFactory *DcmInputFileStream::newFactory() const
{
  DcmInputStreamFactory *result = NULL;
  if (currentProducer() == &producer_)
  {
    // no filter installed, can create factory object
    result = new DcmInputFileStreamFactory(filename_.c_str(), tell());
  }
  return result;
}


/*
 * CVS/RCS Log:
 * $Log: dcistrmf.cc,v $
 * Revision 1.6  2007-02-19 15:45:31  meichel
 * Class DcmInputStream and related classes are now safe for use with
 *   large files (2 GBytes or more) if supported by compiler and operating system.
 *
 * Revision 1.5  2005/12/08 15:41:14  meichel
 * Changed include path schema for all DCMTK header files
 *
 * Revision 1.4  2004/02/04 16:34:09  joergr
 * Adapted type casts to new-style typecast operators defined in ofcast.h.
 *
 * Revision 1.3  2002/11/27 12:06:48  meichel
 * Adapted module dcmdata to use of new header file ofstdinc.h
 *
 * Revision 1.2  2002/09/19 08:32:29  joergr
 * Added explicit type casts to keep Sun CC 2.0.1 quiet.
 *
 * Revision 1.1  2002/08/27 16:55:49  meichel
 * Initial release of new DICOM I/O stream classes that add support for stream
 *   compression (deflated little endian explicit VR transfer syntax)
 *
 *
 */