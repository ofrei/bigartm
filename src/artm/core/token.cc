// Copyright 2017, Additive Regularization of Topic Models.

#include "artm/core/token.h"

namespace artm {
namespace core {

std::ostream& operator<<(std::ostream& os, const shared_string& rhs)
{
  os << rhs.value();
  return os;
}

}  // namespace core
}  // namespace artm
