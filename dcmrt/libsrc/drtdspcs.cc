/*
 *
 *  Copyright (C) 2008-2012, OFFIS e.V. and ICSMED AG, Oldenburg, Germany
 *  Copyright (C) 2013-2014, J. Riesmeier, Oldenburg, Germany
 *  All rights reserved.  See COPYRIGHT file for details.
 *
 *  Source file for class DRTDigitalSignaturePurposeCodeSequence
 *
 *  Generated automatically from DICOM PS 3.3-2007
 *  File created on 2014-03-15 16:58:36
 *
 */


#include "dcmtk/config/osconfig.h"     // make sure OS specific configuration is included first

#include "dcmtk/dcmrt/seq/drtdspcs.h"


// --- item class ---

DRTDigitalSignaturePurposeCodeSequence::Item::Item(const OFBool emptyDefaultItem)
  : EmptyDefaultItem(emptyDefaultItem),
    CodeMeaning(DCM_CodeMeaning),
    CodeValue(DCM_CodeValue),
    CodingSchemeDesignator(DCM_CodingSchemeDesignator),
    CodingSchemeVersion(DCM_CodingSchemeVersion),
    ContextGroupExtensionCreatorUID(DCM_ContextGroupExtensionCreatorUID),
    ContextGroupExtensionFlag(DCM_ContextGroupExtensionFlag),
    ContextGroupLocalVersion(DCM_ContextGroupLocalVersion),
    ContextGroupVersion(DCM_ContextGroupVersion),
    ContextIdentifier(DCM_ContextIdentifier),
    MappingResource(DCM_MappingResource)
{
}


DRTDigitalSignaturePurposeCodeSequence::Item::Item(const Item &copy)
  : EmptyDefaultItem(copy.EmptyDefaultItem),
    CodeMeaning(copy.CodeMeaning),
    CodeValue(copy.CodeValue),
    CodingSchemeDesignator(copy.CodingSchemeDesignator),
    CodingSchemeVersion(copy.CodingSchemeVersion),
    ContextGroupExtensionCreatorUID(copy.ContextGroupExtensionCreatorUID),
    ContextGroupExtensionFlag(copy.ContextGroupExtensionFlag),
    ContextGroupLocalVersion(copy.ContextGroupLocalVersion),
    ContextGroupVersion(copy.ContextGroupVersion),
    ContextIdentifier(copy.ContextIdentifier),
    MappingResource(copy.MappingResource)
{
}


DRTDigitalSignaturePurposeCodeSequence::Item::~Item()
{
}


DRTDigitalSignaturePurposeCodeSequence::Item &DRTDigitalSignaturePurposeCodeSequence::Item::operator=(const Item &copy)
{
    if (this != &copy)
    {
        EmptyDefaultItem = copy.EmptyDefaultItem;
        CodeMeaning = copy.CodeMeaning;
        CodeValue = copy.CodeValue;
        CodingSchemeDesignator = copy.CodingSchemeDesignator;
        CodingSchemeVersion = copy.CodingSchemeVersion;
        ContextGroupExtensionCreatorUID = copy.ContextGroupExtensionCreatorUID;
        ContextGroupExtensionFlag = copy.ContextGroupExtensionFlag;
        ContextGroupLocalVersion = copy.ContextGroupLocalVersion;
        ContextGroupVersion = copy.ContextGroupVersion;
        ContextIdentifier = copy.ContextIdentifier;
        MappingResource = copy.MappingResource;
    }
    return *this;
}


void DRTDigitalSignaturePurposeCodeSequence::Item::clear()
{
    if (!EmptyDefaultItem)
    {
        /* clear all DICOM attributes */
        CodeValue.clear();
        CodingSchemeDesignator.clear();
        CodingSchemeVersion.clear();
        CodeMeaning.clear();
        ContextIdentifier.clear();
        MappingResource.clear();
        ContextGroupVersion.clear();
        ContextGroupExtensionFlag.clear();
        ContextGroupLocalVersion.clear();
        ContextGroupExtensionCreatorUID.clear();
    }
}


OFBool DRTDigitalSignaturePurposeCodeSequence::Item::isEmpty()
{
    return CodeValue.isEmpty() &&
           CodingSchemeDesignator.isEmpty() &&
           CodingSchemeVersion.isEmpty() &&
           CodeMeaning.isEmpty() &&
           ContextIdentifier.isEmpty() &&
           MappingResource.isEmpty() &&
           ContextGroupVersion.isEmpty() &&
           ContextGroupExtensionFlag.isEmpty() &&
           ContextGroupLocalVersion.isEmpty() &&
           ContextGroupExtensionCreatorUID.isEmpty();
}


OFBool DRTDigitalSignaturePurposeCodeSequence::Item::isValid() const
{
    return !EmptyDefaultItem;
}


OFCondition DRTDigitalSignaturePurposeCodeSequence::Item::read(DcmItem &item)
{
    OFCondition result = EC_IllegalCall;
    if (!EmptyDefaultItem)
    {
        /* re-initialize object */
        clear();
        getAndCheckElementFromDataset(item, CodeValue, "1", "1C", "DigitalSignaturePurposeCodeSequence");
        getAndCheckElementFromDataset(item, CodingSchemeDesignator, "1", "1C", "DigitalSignaturePurposeCodeSequence");
        getAndCheckElementFromDataset(item, CodingSchemeVersion, "1", "1C", "DigitalSignaturePurposeCodeSequence");
        getAndCheckElementFromDataset(item, CodeMeaning, "1", "1C", "DigitalSignaturePurposeCodeSequence");
        getAndCheckElementFromDataset(item, ContextIdentifier, "1", "3", "DigitalSignaturePurposeCodeSequence");
        getAndCheckElementFromDataset(item, MappingResource, "1", "1C", "DigitalSignaturePurposeCodeSequence");
        getAndCheckElementFromDataset(item, ContextGroupVersion, "1", "1C", "DigitalSignaturePurposeCodeSequence");
        getAndCheckElementFromDataset(item, ContextGroupExtensionFlag, "1", "3", "DigitalSignaturePurposeCodeSequence");
        getAndCheckElementFromDataset(item, ContextGroupLocalVersion, "1", "1C", "DigitalSignaturePurposeCodeSequence");
        getAndCheckElementFromDataset(item, ContextGroupExtensionCreatorUID, "1", "1C", "DigitalSignaturePurposeCodeSequence");
        result = EC_Normal;
    }
    return result;
}


OFCondition DRTDigitalSignaturePurposeCodeSequence::Item::write(DcmItem &item)
{
    OFCondition result = EC_IllegalCall;
    if (!EmptyDefaultItem)
    {
        result = EC_Normal;
        addElementToDataset(result, item, new DcmShortString(CodeValue), "1", "1C", "DigitalSignaturePurposeCodeSequence");
        addElementToDataset(result, item, new DcmShortString(CodingSchemeDesignator), "1", "1C", "DigitalSignaturePurposeCodeSequence");
        addElementToDataset(result, item, new DcmShortString(CodingSchemeVersion), "1", "1C", "DigitalSignaturePurposeCodeSequence");
        addElementToDataset(result, item, new DcmLongString(CodeMeaning), "1", "1C", "DigitalSignaturePurposeCodeSequence");
        addElementToDataset(result, item, new DcmCodeString(ContextIdentifier), "1", "3", "DigitalSignaturePurposeCodeSequence");
        addElementToDataset(result, item, new DcmCodeString(MappingResource), "1", "1C", "DigitalSignaturePurposeCodeSequence");
        addElementToDataset(result, item, new DcmDateTime(ContextGroupVersion), "1", "1C", "DigitalSignaturePurposeCodeSequence");
        addElementToDataset(result, item, new DcmCodeString(ContextGroupExtensionFlag), "1", "3", "DigitalSignaturePurposeCodeSequence");
        addElementToDataset(result, item, new DcmDateTime(ContextGroupLocalVersion), "1", "1C", "DigitalSignaturePurposeCodeSequence");
        addElementToDataset(result, item, new DcmUniqueIdentifier(ContextGroupExtensionCreatorUID), "1", "1C", "DigitalSignaturePurposeCodeSequence");
    }
    return result;
}


OFCondition DRTDigitalSignaturePurposeCodeSequence::Item::getCodeMeaning(OFString &value, const signed long pos) const
{
    if (EmptyDefaultItem)
        return EC_IllegalCall;
    else
        return getStringValueFromElement(CodeMeaning, value, pos);
}


OFCondition DRTDigitalSignaturePurposeCodeSequence::Item::getCodeValue(OFString &value, const signed long pos) const
{
    if (EmptyDefaultItem)
        return EC_IllegalCall;
    else
        return getStringValueFromElement(CodeValue, value, pos);
}


OFCondition DRTDigitalSignaturePurposeCodeSequence::Item::getCodingSchemeDesignator(OFString &value, const signed long pos) const
{
    if (EmptyDefaultItem)
        return EC_IllegalCall;
    else
        return getStringValueFromElement(CodingSchemeDesignator, value, pos);
}


OFCondition DRTDigitalSignaturePurposeCodeSequence::Item::getCodingSchemeVersion(OFString &value, const signed long pos) const
{
    if (EmptyDefaultItem)
        return EC_IllegalCall;
    else
        return getStringValueFromElement(CodingSchemeVersion, value, pos);
}


OFCondition DRTDigitalSignaturePurposeCodeSequence::Item::getContextGroupExtensionCreatorUID(OFString &value, const signed long pos) const
{
    if (EmptyDefaultItem)
        return EC_IllegalCall;
    else
        return getStringValueFromElement(ContextGroupExtensionCreatorUID, value, pos);
}


OFCondition DRTDigitalSignaturePurposeCodeSequence::Item::getContextGroupExtensionFlag(OFString &value, const signed long pos) const
{
    if (EmptyDefaultItem)
        return EC_IllegalCall;
    else
        return getStringValueFromElement(ContextGroupExtensionFlag, value, pos);
}


OFCondition DRTDigitalSignaturePurposeCodeSequence::Item::getContextGroupLocalVersion(OFString &value, const signed long pos) const
{
    if (EmptyDefaultItem)
        return EC_IllegalCall;
    else
        return getStringValueFromElement(ContextGroupLocalVersion, value, pos);
}


OFCondition DRTDigitalSignaturePurposeCodeSequence::Item::getContextGroupVersion(OFString &value, const signed long pos) const
{
    if (EmptyDefaultItem)
        return EC_IllegalCall;
    else
        return getStringValueFromElement(ContextGroupVersion, value, pos);
}


OFCondition DRTDigitalSignaturePurposeCodeSequence::Item::getContextIdentifier(OFString &value, const signed long pos) const
{
    if (EmptyDefaultItem)
        return EC_IllegalCall;
    else
        return getStringValueFromElement(ContextIdentifier, value, pos);
}


OFCondition DRTDigitalSignaturePurposeCodeSequence::Item::getMappingResource(OFString &value, const signed long pos) const
{
    if (EmptyDefaultItem)
        return EC_IllegalCall;
    else
        return getStringValueFromElement(MappingResource, value, pos);
}


OFCondition DRTDigitalSignaturePurposeCodeSequence::Item::setCodeMeaning(const OFString &value, const OFBool check)
{
    OFCondition result = EC_IllegalCall;
    if (!EmptyDefaultItem)
    {
        result = (check) ? DcmLongString::checkStringValue(value, "1") : EC_Normal;
        if (result.good())
            result = CodeMeaning.putOFStringArray(value);
    }
    return result;
}


OFCondition DRTDigitalSignaturePurposeCodeSequence::Item::setCodeValue(const OFString &value, const OFBool check)
{
    OFCondition result = EC_IllegalCall;
    if (!EmptyDefaultItem)
    {
        result = (check) ? DcmShortString::checkStringValue(value, "1") : EC_Normal;
        if (result.good())
            result = CodeValue.putOFStringArray(value);
    }
    return result;
}


OFCondition DRTDigitalSignaturePurposeCodeSequence::Item::setCodingSchemeDesignator(const OFString &value, const OFBool check)
{
    OFCondition result = EC_IllegalCall;
    if (!EmptyDefaultItem)
    {
        result = (check) ? DcmShortString::checkStringValue(value, "1") : EC_Normal;
        if (result.good())
            result = CodingSchemeDesignator.putOFStringArray(value);
    }
    return result;
}


OFCondition DRTDigitalSignaturePurposeCodeSequence::Item::setCodingSchemeVersion(const OFString &value, const OFBool check)
{
    OFCondition result = EC_IllegalCall;
    if (!EmptyDefaultItem)
    {
        result = (check) ? DcmShortString::checkStringValue(value, "1") : EC_Normal;
        if (result.good())
            result = CodingSchemeVersion.putOFStringArray(value);
    }
    return result;
}


OFCondition DRTDigitalSignaturePurposeCodeSequence::Item::setContextGroupExtensionCreatorUID(const OFString &value, const OFBool check)
{
    OFCondition result = EC_IllegalCall;
    if (!EmptyDefaultItem)
    {
        result = (check) ? DcmUniqueIdentifier::checkStringValue(value, "1") : EC_Normal;
        if (result.good())
            result = ContextGroupExtensionCreatorUID.putOFStringArray(value);
    }
    return result;
}


OFCondition DRTDigitalSignaturePurposeCodeSequence::Item::setContextGroupExtensionFlag(const OFString &value, const OFBool check)
{
    OFCondition result = EC_IllegalCall;
    if (!EmptyDefaultItem)
    {
        result = (check) ? DcmCodeString::checkStringValue(value, "1") : EC_Normal;
        if (result.good())
            result = ContextGroupExtensionFlag.putOFStringArray(value);
    }
    return result;
}


OFCondition DRTDigitalSignaturePurposeCodeSequence::Item::setContextGroupLocalVersion(const OFString &value, const OFBool check)
{
    OFCondition result = EC_IllegalCall;
    if (!EmptyDefaultItem)
    {
        result = (check) ? DcmDateTime::checkStringValue(value, "1") : EC_Normal;
        if (result.good())
            result = ContextGroupLocalVersion.putOFStringArray(value);
    }
    return result;
}


OFCondition DRTDigitalSignaturePurposeCodeSequence::Item::setContextGroupVersion(const OFString &value, const OFBool check)
{
    OFCondition result = EC_IllegalCall;
    if (!EmptyDefaultItem)
    {
        result = (check) ? DcmDateTime::checkStringValue(value, "1") : EC_Normal;
        if (result.good())
            result = ContextGroupVersion.putOFStringArray(value);
    }
    return result;
}


OFCondition DRTDigitalSignaturePurposeCodeSequence::Item::setContextIdentifier(const OFString &value, const OFBool check)
{
    OFCondition result = EC_IllegalCall;
    if (!EmptyDefaultItem)
    {
        result = (check) ? DcmCodeString::checkStringValue(value, "1") : EC_Normal;
        if (result.good())
            result = ContextIdentifier.putOFStringArray(value);
    }
    return result;
}


OFCondition DRTDigitalSignaturePurposeCodeSequence::Item::setMappingResource(const OFString &value, const OFBool check)
{
    OFCondition result = EC_IllegalCall;
    if (!EmptyDefaultItem)
    {
        result = (check) ? DcmCodeString::checkStringValue(value, "1") : EC_Normal;
        if (result.good())
            result = MappingResource.putOFStringArray(value);
    }
    return result;
}


// --- sequence class ---

DRTDigitalSignaturePurposeCodeSequence::DRTDigitalSignaturePurposeCodeSequence(const OFBool emptyDefaultSequence)
  : EmptyDefaultSequence(emptyDefaultSequence),
    SequenceOfItems(),
    CurrentItem(),
    EmptyItem(OFTrue /*emptyDefaultItem*/)
{
    CurrentItem = SequenceOfItems.end();
}


DRTDigitalSignaturePurposeCodeSequence::DRTDigitalSignaturePurposeCodeSequence(const DRTDigitalSignaturePurposeCodeSequence &copy)
  : EmptyDefaultSequence(copy.EmptyDefaultSequence),
    SequenceOfItems(),
    CurrentItem(),
    EmptyItem(OFTrue /*emptyDefaultItem*/)
{
    /* create a copy of the internal sequence of items */
    Item *item = NULL;
    OFListConstIterator(Item *) current = copy.SequenceOfItems.begin();
    const OFListConstIterator(Item *) last = copy.SequenceOfItems.end();
    while (current != last)
    {
        item = new Item(**current);
        if (item != NULL)
        {
            SequenceOfItems.push_back(item);
        } else {
            /* memory exhausted, there is nothing we can do about it */
            break;
        }
        ++current;
    }
    CurrentItem = SequenceOfItems.begin();
}


DRTDigitalSignaturePurposeCodeSequence &DRTDigitalSignaturePurposeCodeSequence::operator=(const DRTDigitalSignaturePurposeCodeSequence &copy)
{
    if (this != &copy)
    {
        clear();
        EmptyDefaultSequence = copy.EmptyDefaultSequence;
        /* create a copy of the internal sequence of items */
        Item *item = NULL;
        OFListConstIterator(Item *) current = copy.SequenceOfItems.begin();
        const OFListConstIterator(Item *) last = copy.SequenceOfItems.end();
        while (current != last)
        {
            item = new Item(**current);
            if (item != NULL)
            {
                SequenceOfItems.push_back(item);
            } else {
                /* memory exhausted, there is nothing we can do about it */
                break;
            }
            ++current;
        }
        CurrentItem = SequenceOfItems.begin();
    }
    return *this;
}


DRTDigitalSignaturePurposeCodeSequence::~DRTDigitalSignaturePurposeCodeSequence()
{
    clear();
}


void DRTDigitalSignaturePurposeCodeSequence::clear()
{
    if (!EmptyDefaultSequence)
    {
        CurrentItem = SequenceOfItems.begin();
        const OFListConstIterator(Item *) last = SequenceOfItems.end();
        /* delete all items and free memory */
        while (CurrentItem != last)
        {
            delete (*CurrentItem);
            CurrentItem = SequenceOfItems.erase(CurrentItem);
        }
        /* make sure that the list is empty */
        SequenceOfItems.clear();
        CurrentItem = SequenceOfItems.end();
    }
}


OFBool DRTDigitalSignaturePurposeCodeSequence::isEmpty()
{
    return SequenceOfItems.empty();
}


OFBool DRTDigitalSignaturePurposeCodeSequence::isValid() const
{
    return !EmptyDefaultSequence;
}


unsigned long DRTDigitalSignaturePurposeCodeSequence::getNumberOfItems() const
{
    return SequenceOfItems.size();
}


OFCondition DRTDigitalSignaturePurposeCodeSequence::gotoFirstItem()
{
    OFCondition result = EC_IllegalCall;
    if (!SequenceOfItems.empty())
    {
        CurrentItem = SequenceOfItems.begin();
        result = EC_Normal;
    }
    return result;
}


OFCondition DRTDigitalSignaturePurposeCodeSequence::gotoNextItem()
{
    OFCondition result = EC_IllegalCall;
    if (CurrentItem != SequenceOfItems.end())
    {
        ++CurrentItem;
        result = EC_Normal;
    }
    return result;
}


OFCondition DRTDigitalSignaturePurposeCodeSequence::gotoItem(const unsigned long num, OFListIterator(Item *) &iterator)
{
    OFCondition result = EC_IllegalCall;
    if (!SequenceOfItems.empty())
    {
        unsigned long idx = num + 1;
        iterator = SequenceOfItems.begin();
        const OFListConstIterator(Item *) last = SequenceOfItems.end();
        while ((--idx > 0) && (iterator != last))
            ++iterator;
        /* specified list item found? */
        if ((idx == 0) && (iterator != last))
            result = EC_Normal;
        else
            result = EC_IllegalParameter;
    }
    return result;
}


OFCondition DRTDigitalSignaturePurposeCodeSequence::gotoItem(const unsigned long num, OFListConstIterator(Item *) &iterator) const
{
    OFCondition result = EC_IllegalCall;
    if (!SequenceOfItems.empty())
    {
        unsigned long idx = num + 1;
        iterator = SequenceOfItems.begin();
        const OFListConstIterator(Item *) last = SequenceOfItems.end();
        while ((--idx > 0) && (iterator != last))
            ++iterator;
        /* specified list item found? */
        if ((idx == 0) && (iterator != last))
            result = EC_Normal;
        else
            result = EC_IllegalParameter;
    }
    return result;
}


OFCondition DRTDigitalSignaturePurposeCodeSequence::gotoItem(const unsigned long num)
{
    return gotoItem(num, CurrentItem);
}


OFCondition DRTDigitalSignaturePurposeCodeSequence::getCurrentItem(Item *&item) const
{
    OFCondition result = EC_IllegalCall;
    if (CurrentItem != SequenceOfItems.end())
    {
        item = *CurrentItem;
        result = EC_Normal;
    }
    return result;
}


DRTDigitalSignaturePurposeCodeSequence::Item &DRTDigitalSignaturePurposeCodeSequence::getCurrentItem()
{
    if (CurrentItem != SequenceOfItems.end())
        return **CurrentItem;
    else
        return EmptyItem;
}


const DRTDigitalSignaturePurposeCodeSequence::Item &DRTDigitalSignaturePurposeCodeSequence::getCurrentItem() const
{
    if (CurrentItem != SequenceOfItems.end())
        return **CurrentItem;
    else
        return EmptyItem;
}


OFCondition DRTDigitalSignaturePurposeCodeSequence::getItem(const unsigned long num, Item *&item)
{
    OFListIterator(Item *) iterator;
    OFCondition result = gotoItem(num, iterator);
    if (result.good())
        item = *iterator;
    return result;
}


DRTDigitalSignaturePurposeCodeSequence::Item &DRTDigitalSignaturePurposeCodeSequence::getItem(const unsigned long num)
{
    OFListIterator(Item *) iterator;
    if (gotoItem(num, iterator).good())
        return **iterator;
    else
        return EmptyItem;
}


const DRTDigitalSignaturePurposeCodeSequence::Item &DRTDigitalSignaturePurposeCodeSequence::getItem(const unsigned long num) const
{
    OFListConstIterator(Item *) iterator;
    if (gotoItem(num, iterator).good())
        return **iterator;
    else
        return EmptyItem;
}


DRTDigitalSignaturePurposeCodeSequence::Item &DRTDigitalSignaturePurposeCodeSequence::operator[](const unsigned long num)
{
    return getItem(num);
}


const DRTDigitalSignaturePurposeCodeSequence::Item &DRTDigitalSignaturePurposeCodeSequence::operator[](const unsigned long num) const
{
    return getItem(num);
}


OFCondition DRTDigitalSignaturePurposeCodeSequence::addItem(Item *&item)
{
    OFCondition result = EC_IllegalCall;
    if (!EmptyDefaultSequence)
    {
        item = new Item();
        if (item != NULL)
        {
            SequenceOfItems.push_back(item);
            result = EC_Normal;
        } else
            result = EC_MemoryExhausted;
    }
    return result;
}


OFCondition DRTDigitalSignaturePurposeCodeSequence::insertItem(const unsigned long pos, Item *&item)
{
    OFCondition result = EC_IllegalCall;
    if (!EmptyDefaultSequence)
    {
        OFListIterator(Item *) iterator;
        result = gotoItem(pos, iterator);
        if (result.good())
        {
            item = new Item();
            if (item != NULL)
            {
                SequenceOfItems.insert(iterator, 1, item);
                result = EC_Normal;
            } else
                result = EC_MemoryExhausted;
        } else
            result = addItem(item);
    }
    return result;
}


OFCondition DRTDigitalSignaturePurposeCodeSequence::removeItem(const unsigned long pos)
{
    OFCondition result = EC_IllegalCall;
    if (!EmptyDefaultSequence)
    {
        OFListIterator(Item *) iterator;
        if (gotoItem(pos, iterator).good())
        {
            delete *iterator;
            iterator = SequenceOfItems.erase(iterator);
            result = EC_Normal;
        } else
            result = EC_IllegalParameter;
    }
    return result;
}


OFCondition DRTDigitalSignaturePurposeCodeSequence::read(DcmItem &dataset,
                                                         const OFString &card,
                                                         const OFString &type,
                                                         const char *moduleName)
{
    OFCondition result = EC_IllegalCall;
    if (!EmptyDefaultSequence)
    {
        /* re-initialize object */
        clear();
        /* retrieve sequence element from dataset */
        DcmSequenceOfItems *sequence;
        result = dataset.findAndGetSequence(DCM_DigitalSignaturePurposeCodeSequence, sequence);
        if (sequence != NULL)
        {
            if (checkElementValue(*sequence, card, type, result, moduleName))
            {
                DcmStack stack;
                OFBool first = OFTrue;
                /* iterate over all sequence items */
                while (result.good() && sequence->nextObject(stack, first /*intoSub*/).good())
                {
                    DcmItem *ditem = OFstatic_cast(DcmItem *, stack.top());
                    if (ditem != NULL)
                    {
                        Item *item = new Item();
                        if (item != NULL)
                        {
                            result = item->read(*ditem);
                            if (result.good())
                            {
                                /* append new item to the end of the list */
                                SequenceOfItems.push_back(item);
                                first = OFFalse;
                            }
                        } else
                            result = EC_MemoryExhausted;
                    } else
                        result = EC_CorruptedData;
                }
            }
        } else {
            DcmSequenceOfItems element(DCM_DigitalSignaturePurposeCodeSequence);
            checkElementValue(element, card, type, result, moduleName);
        }
    }
    return result;
}


OFCondition DRTDigitalSignaturePurposeCodeSequence::write(DcmItem &dataset,
                                                          const OFString &card,
                                                          const OFString &type,
                                                          const char *moduleName)
{
    OFCondition result = EC_IllegalCall;
    if (!EmptyDefaultSequence)
    {
        result = EC_MemoryExhausted;
        DcmSequenceOfItems *sequence = new DcmSequenceOfItems(DCM_DigitalSignaturePurposeCodeSequence);
        if (sequence != NULL)
        {
            result = EC_Normal;
            /* an empty optional sequence is not written */
            if ((type == "2") || !SequenceOfItems.empty())
            {
                OFListIterator(Item *) iterator = SequenceOfItems.begin();
                const OFListConstIterator(Item *) last = SequenceOfItems.end();
                /* iterate over all sequence items */
                while (result.good() && (iterator != last))
                {
                    DcmItem *item = new DcmItem();
                    if (item != NULL)
                    {
                        /* append new item to the end of the sequence */
                        result = sequence->append(item);
                        if (result.good())
                        {
                            result = (*iterator)->write(*item);
                            ++iterator;
                        } else
                            delete item;
                    } else
                        result = EC_MemoryExhausted;
                }
                if (result.good())
                {
                    /* insert sequence element into the dataset */
                    result = dataset.insert(sequence, OFTrue /*replaceOld*/);
                }
                if (DCM_dcmrtLogger.isEnabledFor(OFLogger::WARN_LOG_LEVEL))
                    checkElementValue(*sequence, card, type, result, moduleName);
                if (result.good())
                {
                    /* forget reference to sequence object (avoid deletion below) */
                    sequence = NULL;
                }
            }
            else if (type == "1")
            {
                /* empty type 1 sequence not allowed */
                result = RT_EC_InvalidValue;
                if (DCM_dcmrtLogger.isEnabledFor(OFLogger::WARN_LOG_LEVEL))
                    checkElementValue(*sequence, card, type, result, moduleName);
            }
            /* delete sequence (if not inserted into the dataset) */
            delete sequence;
        }
    }
    return result;
}


// end of source file
