#include "pcl_utilization/pcl_utilization.h"

double pcl_utilization::computeCloudResolution(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud)
{
    double resolution = 0.0;
    int numberOfPoints = 0;
    int nres;
    std::vector<int> indices(2);
    std::vector<float> squaredDistances(2);
    pcl::search::KdTree<pcl::PointXYZ> tree;
    tree.setInputCloud(cloud);

    for (size_t i = 0; i < cloud->size(); ++i)
    {
        if (!std::isfinite((*cloud)[i].x))
            continue;

        // Considering the second neighbor since the first is the point itself.
        nres = tree.nearestKSearch(i, 2, indices, squaredDistances);
        if (nres == 2)
        {
            resolution += sqrt(squaredDistances[1]);
            ++numberOfPoints;
        }
    }
    if (numberOfPoints != 0)
        resolution /= numberOfPoints;
    // std::cout << "number of point: " << numberOfPoints << std::endl;
    return resolution;
}

double pcl_utilization::computeCloudResolution(pcl::PointCloud<pcl::PointNormal>::Ptr cloudWithNormals)
{
    double resolution = 0.0;
    int numberOfPoints = 0;
    int nres;
    std::vector<int> indices(2);
    std::vector<float> squaredDistances(2);
    pcl::search::KdTree<pcl::PointNormal> tree;
    tree.setInputCloud(cloudWithNormals);

    for (size_t i = 0; i < cloudWithNormals->size(); ++i)
    {
        if (!std::isfinite((*cloudWithNormals)[i].x))
            continue;

        // Considering the second neighbor since the first is the point itself.
        nres = tree.nearestKSearch(i, 2, indices, squaredDistances);
        if (nres == 2)
        {
            resolution += sqrt(squaredDistances[1]);
            ++numberOfPoints;
        }
    }
    if (numberOfPoints != 0)
        resolution /= numberOfPoints;
    // std::cout << "number of point: " << numberOfPoints << std::endl;
    return resolution;
}

std::vector<std::vector<double>> pcl_utilization::computeAABB(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud)
{
    int cloud_size = cloud->points.size(); // Number of the points
    std::vector<std::vector<double>> result;
    std::vector<double> max;
    std::vector<double> min;

    max.push_back(cloud->points[0].x);
    max.push_back(cloud->points[0].y);
    max.push_back(cloud->points[0].z);
    min.push_back(cloud->points[0].x);
    min.push_back(cloud->points[0].y);
    min.push_back(cloud->points[0].z);

    for (int i = 1; i < cloud_size; i++)
    {
        if (cloud->points[i].x > max[0])
        {
            max[0] = cloud->points[i].x;
        }
        else if (cloud->points[i].x < min[0])
        {
            min[0] = cloud->points[i].x;
        }
        else;

        if (cloud->points[i].y > max[1])
        {
            max[1] = cloud->points[i].y;
        }
        else if (cloud->points[i].y < min[1])
        {
            min[1] = cloud->points[i].y;
        }
        else;


        if (cloud->points[i].z > max[2])
        {
            max[2] = cloud->points[i].z;
        }
        else if (cloud->points[i].z < min[2])
        {
            min[2] = cloud->points[i].z;
        }
        else;
    }

    result.push_back(max);
    result.push_back(min);
    return result;
}


std::vector<std::vector<double>> pcl_utilization::computeAABB(pcl::PointCloud<pcl::PointNormal>::Ptr cloud)
{
    int cloud_size = cloud->points.size(); // Number of the points
    std::vector<std::vector<double>> result;
    std::vector<double> max;
    std::vector<double> min;

    max.push_back(cloud->points[0].x);
    max.push_back(cloud->points[0].y);
    max.push_back(cloud->points[0].z);
    min.push_back(cloud->points[0].x);
    min.push_back(cloud->points[0].y);
    min.push_back(cloud->points[0].z);

    for (int i = 1; i < cloud_size; i++)
    {
        if (cloud->points[i].x > max[0])
        {
            max[0] = cloud->points[i].x;
        }
        else if (cloud->points[i].x < min[0])
        {
            min[0] = cloud->points[i].x;
        }
        else;

        if (cloud->points[i].y > max[1])
        {
            max[1] = cloud->points[i].y;
        }
        else if (cloud->points[i].y < min[1])
        {
            min[1] = cloud->points[i].y;
        }
        else;

        if (cloud->points[i].z > max[2])
        {
            max[2] = cloud->points[i].z;
        }
        else if (cloud->points[i].z < min[2])
        {
            min[2] = cloud->points[i].z;
        }
        else;
    }

    result.push_back(max);
    result.push_back(min);
    return result;
}
