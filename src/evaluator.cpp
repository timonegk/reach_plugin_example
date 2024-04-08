#include <reach/interfaces/evaluator.h>
class ExampleEvaluator : public reach::Evaluator {
public:
  ExampleEvaluator() {};
  double calculateScore(const std::map<std::string, double>& pose) const override { return 2.0; }
};

struct ExampleEvaluatorFactory : public reach::EvaluatorFactory {
  reach::Evaluator::ConstPtr create(const YAML::Node& config) const override { return std::make_shared<ExampleEvaluator>(); }
};

#include <reach/plugin_utils.h>
EXPORT_EVALUATOR_PLUGIN(ExampleEvaluatorFactory, ExampleEvaluator)
