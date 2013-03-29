#pragma once
#include <vector>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

class Edge
{
public:
	Edge(void);
	int getStartEdgeRow();
	int getStartEdgeColumn();
	int getEndEdgeRow();
	int getEndEdgeColumn();
	void setStartEdgeRow(int row);
	void setStartEdgeColumn(int column);
	void setLength(int length);
	int getLength();
	int getEdgeSumCanny();
	int getEdgeSumOriginal();
	void compute(Mat image, Mat image2);

	virtual ~Edge(void);
private:
	int startEdgeRow;
	int startEdgeColumn;
	int endEdgeRow;
	int endEdgeColumn;
	int length;
	int edgeSumCanny;
	int edgeSumOriginal;
	vector<int> edgeVectorCanny;
	vector<int> edgeVectorOriginal;
};

