#ifndef INCL_BASE_UNCLONEABLE_H
#define INCL_BASE_UNCLONEABLE_H


/*! \brief The Uncloneable interface.
*
* for example:
* \code
*  class Asn1Decoder : private Uncloneable
*  {
*  public:
*      static const Asn1Decoder& getInstance();
*  private:
*      Asn1Decoder();
*  }
* \endcode
*/

class Uncloneable
{
protected:
    Uncloneable() {}
    ~Uncloneable(){}

private:
    Uncloneable(const Uncloneable&);
    Uncloneable& operator=(const Uncloneable&);
};


#define DISALLOW_COPY_AND_ASSIGN(ClassName)             \
private:                                                \
    ClassName(const ClassName&);                        \
    ClassName& operator=(const ClassName&);

#define DISALLOW_ASSIGN(ClassName)                      \
private:                                                \
    ClassName& operator=(const ClassName&);

#define DISALLOW_COPY(ClassName)                        \
private:                                                \
    ClassName(const ClassName&);                        \

#endif

