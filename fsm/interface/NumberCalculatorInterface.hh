#pragma once

//abstract interface class, to force derived classes implement methods listed below

class NumberCalculatorInterface
{
public:
    virtual ~NumberCalculatorInterface() {};

/*
    virtual void storeMetadata(const ImbeFrameMetadata& metadata, const non_rosert::PayloadSource source) = 0;
    virtual bool stopStream(const non_rosert::PayloadSource source) = 0;
    virtual ImbeFrameMetadata getMetadata() = 0;
*/
};
