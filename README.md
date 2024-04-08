This is an example of a simple reach plugin that results in a segmentation fault.

Instructions:
- clone this repository
- replace `NoOpEvaluator` with `ExampleEvaluator` in `reach/test/reach_study.yaml`
- build reach and this repository with colcon
- navigate to your reach repository and run `REACH_PLUGINS=reach_plugin_example python ./scripts/test_reach.py`
