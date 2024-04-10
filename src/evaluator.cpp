#include "evaluator.hpp"

ExampleEvaluator::ExampleEvaluator() {};
double ExampleEvaluator::calculateScore(const std::map<std::string, double>& pose) const { return 2.0; }

reach::Evaluator::ConstPtr ExampleEvaluatorFactory::create(const YAML::Node& config) const { return std::make_shared<ExampleEvaluator>(); }
