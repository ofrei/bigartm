// Copyright 2014, Additive Regularization of Topic Models.

// Author: Murat Apishev (great-mel@yandex.ru)

#include <cmath>

#include <memory>

#include "artm/core/transform_function.h"

namespace artm {
namespace core {

std::shared_ptr<TransformFunction> TransformFunction::create(const TransformConfig& config) {
  switch (config.type()) {
    case TransformConfig_TransformType_Constant:
      return std::make_shared<ConstantTransformFunction>(ConstantTransformFunction());

    case TransformConfig_TransformType_Logarithm:
      return std::make_shared<LogarithmTransformFunction>(LogarithmTransformFunction());

    case TransformConfig_TransformType_Polynomial:
      return std::make_shared<PolynomialTransformFunction>(PolynomialTransformFunction(config.a(), config.n()));
  }

  BOOST_THROW_EXCEPTION(InvalidOperation("Invalid TransformConfig.type"));
}

std::shared_ptr<TransformFunction> TransformFunction::create() {
  TransformConfig config;
  config.set_type(TransformConfig_TransformType_Constant);
  return TransformFunction::create(config);
}

double LogarithmTransformFunction::apply(double value) {
  return value > 0 ? log(value) : 0.0;
}

PolynomialTransformFunction::PolynomialTransformFunction(double a, double n) : a_(a), n_(n) { }

double PolynomialTransformFunction::apply(double value) {
  return value > 0 ? a_ * pow(value, n_) : 0.0;
}

double ConstantTransformFunction::apply(double value) {
  return 1.0;
}

}  // namespace core
}  // namespace artm
