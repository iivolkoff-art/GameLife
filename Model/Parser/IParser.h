#ifndef IPARSER_H
#define IPARSER_H

template<typename T, typename M>
class IParser{
public:
    virtual T parse(const M& data) const = 0;
    virtual ~IParser() = default;
};

#endif // IPARSER_H
