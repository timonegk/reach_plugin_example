#include <reach/interfaces/evaluator.h>

class ExampleEvaluator : public reach::Evaluator {
public:
  ExampleEvaluator();
  double calculateScore(const std::map<std::string, double>& pose) const override;
};

