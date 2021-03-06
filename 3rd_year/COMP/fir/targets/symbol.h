#ifndef __FIR_TARGETS_SYMBOL_H__
#define __FIR_TARGETS_SYMBOL_H__

#include <string>
#include <memory>
#include <cdk/types/basic_type.h>

namespace fir {

  class symbol {
    int _qualifier; /* tPRIVATE || tPUBLIC || tEXTERNAL*/
    std::shared_ptr<cdk::basic_type> _type;
    std::string _name;
    long _value; // hack!

  public:
    symbol(std::shared_ptr<cdk::basic_type> type, const std::string &name, long value) :
        _type(type), _name(name), _value(value) {
    }

    virtual ~symbol() {
      // EMPTY
    }
    int qualifier() const {
      return _qualifier;
    }
    std::shared_ptr<cdk::basic_type> type() const {
      return _type;
    }
    bool is_typed(cdk::typename_type name) const {
      return _type->name() == name;
    }
    const std::string &name() const {
      return _name;
    }
    long value() const {
      return _value;
    }
    long value(long v) {
      return _value = v;
    }
  };
  
  inline auto make_symbol(int qualifier, std::shared_ptr<cdk::basic_type> type, const std::string &name, long value) {
    return std::make_shared<symbol>(type, name, value);
  }

} // fir

#endif
