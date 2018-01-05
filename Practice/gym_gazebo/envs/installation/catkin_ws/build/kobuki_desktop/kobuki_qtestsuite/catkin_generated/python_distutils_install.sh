#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
    DESTDIR_ARG="--root=$DESTDIR"
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/howoongjun/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/src/kobuki_desktop/kobuki_qtestsuite"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/howoongjun/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/install/lib/python2.7/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/howoongjun/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/install/lib/python2.7/dist-packages:/home/howoongjun/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/build/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/howoongjun/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/build" \
    "/home/howoongjun/anaconda2/bin/python" \
    "/home/howoongjun/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/src/kobuki_desktop/kobuki_qtestsuite/setup.py" \
    build --build-base "/home/howoongjun/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/build/kobuki_desktop/kobuki_qtestsuite" \
    install \
    $DESTDIR_ARG \
    --install-layout=deb --prefix="/home/howoongjun/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/install" --install-scripts="/home/howoongjun/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/install/bin"
