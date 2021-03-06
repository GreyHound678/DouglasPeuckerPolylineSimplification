/*=========================================================================
 *
 *  Copyright David Doria 2011 daviddoria@gmail.com
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/

#include "DouglasPeuckerITK.h"

void CreateContour(itk::PolyLineParametricPath< 2 >::Pointer contour);

int main(int argc, char *argv[])
{
  // The larger the tolerance, the more reduction will take place.
  float approximationTolerance = 1.0;
  
  itk::PolyLineParametricPath< 2 >::Pointer path = itk::PolyLineParametricPath< 2 >::New();
  CreateContour(path);  
  std::cout << "There are " << path->GetVertexList()->Size() << " points in the input path." << std::endl;
  
  itk::PolyLineParametricPath< 2 >::Pointer simplifiedPath = itk::PolyLineParametricPath< 2 >::New();
  SimplifyPolyline( path, approximationTolerance, simplifiedPath);
  
  std::cout << "There are " << simplifiedPath->GetVertexList()->Size() << " points in the simplified path." << std::endl;
  
  return 0;
}

void CreateContour(itk::PolyLineParametricPath< 2 >::Pointer contour)
{
  
  float points[154] = {
  0.0, 0.000985395,
0.041631, 1.17664,
0.364602, 2.09133,
0.0922976, 3.48722,
0.52675, 4.45443,
0.233178, 5.83129,
0.931731, 6.56806,
0.556094, 7.05083,
0.767051, 8.01891,
0.25236, 9.2982,
0.875981, 10.5316,
0.920261, 11.5154,
0.810429, 12.1884,
0.886314, 13.5706,
0.0767746, 14.8153,
0.984891, 15.1184,
0.893906, 16.7845,
0.100916, 17.2533,
0.0198417, 18.3784,
0.678877, 19.6809,
0.752707, 19.0062,
1.62441, 19.1265,
2.61755, 19.7709,
3.18654, 19.4967,
4.5095, 19.3159,
5.7017, 19.3672,
6.87631, 19.371,
7.52525, 19.4278,
8.54274, 19.668,
9.17114, 19.8308,
10.8619, 19.7692,
11.0526, 19.9667,
12.3343, 19.0821,
13.2703, 19.0743,
14.6762, 19.8102,
15.4642, 19.5692,
16.5122, 19.5865,
17.7388, 19.8717,
18.578, 19.9647,
19.3335, 18.3928,
19.1769, 17.1119,
19.8527, 16.8112,
19.9549, 15.9043,
19.1389, 14.6862,
19.127, 13.0041,
19.0005, 12.193,
19.5868, 11.375,
19.0268, 10.4648,
19.7853, 9.44223,
19.2879, 8.85335,
19.526, 7.72842,
19.2663, 6.78348,
19.468, 5.197,
19.4472, 4.72844,
19.9661, 3.75684,
19.4661, 2.86897,
19.134, 1.84605,
19.0181, 0.940855,
18.6701, 0.799972,
17.1432, 0.61046,
16.9083, 0.774415,
15.3661, 0.944288,
14.8848, 0.445171,
13.163, 0.424817,
12.4799, 0.0311283,
11.6084, 0.792261,
10.1825, 0.525121,
9.89876, 0.30879,
8.94263, 0.388025,
7.93051, 0.911384,
6.33772, 0.532812,
5.70208, 0.971011,
4.76809, 0.751941,
3.09086, 0.853967,
2.17464, 0.0197704,
1.41905, 0.29637,
0.378232, 0.418716};

  typedef itk::PolyLineParametricPath< 2 >::ContinuousIndexType    ContinuousIndexType;
  ContinuousIndexType cindex;

  contour->Initialize();
  for(unsigned int i = 0; i < 77; ++i)
    {
    cindex[0] = points[2*i+0];
    cindex[1] = points[2*i+1];
    contour->AddVertex( cindex );
    }
}
