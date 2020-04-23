/**
 * @file
 * @brief The entry point for the do_something_big node
 *
 * @author Henrik Stickann
 */

#include "do_something_big_node/do_something_big.h"

#include <igmr_node_interface/exceptions.h>

#include <ros/ros.h>


int main(int argc, char ** argv)
{
    // ROS initialization has to come first
    ros::init(argc, argv, "do_something_big");

    try {
        // Instantiate object and run node logic
        template_nodes::DoSomethingBig node_impl;

        node_impl.run();
    }
    catch (const igmr_node_interface::NodeException & e)
    {
        // Handle exceptions thrown by nodes
        ROS_ERROR_STREAM("Node died with exception: " << e.what());
        
        return -1;
    }
    catch (const std::exception & e)
    {
        // Handle exceptions not caught by node logic
        ROS_ERROR_STREAM("Node died because of uncaught exception: " << e.what());

        return -1;
    }

    return 0;
}
