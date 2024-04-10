#include "evaluator.hpp"

struct ExampleEvaluatorFactory : public reach::EvaluatorFactory {
  reach::Evaluator::ConstPtr create(const YAML::Node& config) const override { return std::make_shared<ExampleEvaluator>(); }
};

#include <reach/plugin_utils.h>
EXPORT_EVALUATOR_PLUGIN(ExampleEvaluatorFactory, ExampleEvaluator)
