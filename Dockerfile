FROM ros:rolling

RUN apt update && apt install python3-pip python3-tqdm -y
WORKDIR /ws/src
RUN git clone https://github.com/ros-industrial/reach.git
RUN rosdep install -iry --from-paths reach
RUN sed -i 's/NoOpEvaluator/ExampleEvaluator/' reach/test/reach_study.yaml
RUN git clone https://github.com/tesseract-robotics/boost_plugin_loader.git
ADD . reach_plugin_example
WORKDIR /ws
RUN bash -c 'source /opt/ros/rolling/setup.bash && colcon build'
ENV REACH_PLUGINS=reach_plugin_example
ENV PYTHONPATH=/ws/install/reach/lib/python3/dist-packages
RUN bash -c 'source /ws/install/setup.bash && python3 /ws/src/reach/scripts/test_reach.py'
