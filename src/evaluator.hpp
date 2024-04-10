#include <reach/interfaces/evaluator.h>

class ExampleEvaluator : public reach::Evaluator {
public:
  ExampleEvaluator();
  double calculateScore(const std::map<std::string, double>& pose) const override;
};

struct ExampleEvaluatorFactory : public reach::EvaluatorFactory {
  reach::Evaluator::ConstPtr create(const YAML::Node& config) const override;
};

