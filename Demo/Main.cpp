#include <windows.h>
#include <gl/GL.h>
#include <math.h>
#include <gl/GLU.h>
#include <stdio.h>
#include "Tree.h"
#include <time.h>
#include "Raindrop.h"
#include "Students.h"

#define WIN_WIDTH 800
#define WIN_HEIGHT 600

#pragma comment(lib,"opengl32.lib")

typedef enum VALUETYPE
{
	EYEX = 1,
	EYEY,
	EYEZ,
	XROTATE,
	YROTATE
}ValueType;

typedef struct POSITIONS
{
	GLfloat values[700] = {
		0.700000f,
		1.400000f,
		2.100000f,
		-0.700000f,
		0.000000f,
		-0.700000f,
		-1.400000f,
		-2.100000f,
		-2.800000f,
		-3.500000f,
		-4.200000f,
		-4.900000f,
		-5.599999f,
		-6.299999f,
		-6.999999f,
		-7.699999f,
		-8.399999f,
		-9.099998f,
		-9.799998f,
		-10.49999f,
		-11.19999f,
		-11.89999f,
		-12.59999f,
		-13.29999f,
		-13.99999f,
		-14.69999f,
		-15.39999f,
		-16.09999f,
		-16.79999f,
		-17.49999f,
		-18.19999f,
		-18.90000f,
		-19.60000f,
		-20.30000f,
		-21.00000f,
		0.700000f,
		1.400000f,
		2.100000f,
		2.800000f,
		3.500000f,
		4.200000f,
		4.900000f,
		5.599999f,
		6.299999f,
		6.999999f,
		-21.70000f,
		-22.40000f,
		-23.10000f,
		-23.80000f,
		-24.50000f,
		-25.20000f,
		7.699999f,
		8.399999f,
		9.099998f,
		9.799998f,
		10.499998f,
		11.199998f,
		11.899998f,
		12.599998f,
		13.299997f,
		13.999997f,
		14.699997f,
		15.399997f,
		16.099997f,
		16.799997f,
		17.499998f,
		18.199999f,
		18.900000f,
		19.600000f,
		20.300001f,
		21.000002f,
		21.700003f,
		22.400003f,
		23.100004f,
		23.800005f,
		24.500006f,
		25.200006f,
		25.900007f,
		26.600008f,
		27.300009f,
		28.000010f,
		28.700010f,
		29.400011f,
		30.100012f,
		30.800013f,
		31.500013f,
		32.200012f,
		32.900013f,
		33.600014f,
		34.300014f,
		35.000015f,
		35.700016f,
		36.400017f,
		37.100018f,
		37.800018f,
		38.500019f,
		39.200020f,
		39.900021f,
		40.600021f,
		41.300022f,
		42.000023f,
		42.700024f,
		43.400024f,
		44.100025f,
		44.800026f,
		45.500027f,
		46.200027f,
		46.900028f,
		47.600029f,
		48.300030f,
		49.000031f,
		49.700031f,
		50.400032f,
		51.100033f,
		51.800034f,
		52.500034f,
		53.200035f,
		53.900036f,
		54.600037f,
		55.300037f,
		56.000038f,
		56.700039f,
		57.400040f,
		58.100040f,
		58.800041f,
		59.500042f,
		60.200043f,
		60.900043f,
		61.600044f,
		62.300045f,
		63.000046f,
		63.700047f,
		64.400047f,
		65.100044f,
		65.800041f,
		66.500038f,
		67.200035f,
		67.900032f,
		68.600029f,
		69.300026f,
		70.000023f,
		70.700020f,
		71.400017f,
		72.100014f,
		72.800011f,
		73.500008f,
		74.200005f,
		73.500008f,
		72.800011f,
		72.100014f,
		71.400017f,
		70.700020f,
		70.000023f,
		69.300026f,
		68.600029f,
		67.900032f,
		67.200035f,
		66.500038f,
		65.800041f,
		65.100044f,
		64.400047f,
		63.700047f,
		63.000046f,
		62.300045f,
		61.600044f,
		60.900043f,
		60.200043f,
		59.500042f,
		58.800041f,
		58.100040f,
		57.400040f,
		56.700039f,
		56.000038f,
		55.300037f,
		54.600037f,
		53.900036f,
		53.200035f,
		52.500034f,
		51.800034f,
		51.100033f,
		50.400032f,
		49.700031f,
		49.000031f,
		48.300030f,
		47.600029f,
		46.900028f,
		46.200027f,
		45.500027f,
		44.800026f,
		44.100025f,
		43.400024f,
		42.700024f,
		42.000023f,
		41.300022f,
		40.600021f,
		39.900021f,
		39.200020f,
		38.500019f,
		37.800018f,
		37.100018f,
		36.400017f,
		35.700016f,
		35.000015f,
		34.300014f,
		33.600014f,
		32.900013f,
		32.200012f,
		31.500011f,
		30.800011f,
		30.100010f,
		29.400009f,
		28.700008f,
		28.000008f,
		27.300007f,
		26.600006f,
		25.900005f,
		25.200005f,
		24.500004f,
		23.800003f,
		23.100002f,
		22.400002f,
		2.800000f,
		21.700001f,
		21.000000f,
		20.299999f,
		19.599998f,
		18.899998f,
		18.199997f,
		17.499996f,
		16.799995f,
		16.099995f,
		15.399995f,
		14.699995f,
		3.500000f,
		13.999995f,
		13.299995f,
		12.599996f,
		11.899996f,
		11.199996f,
		10.499996f,
		9.799996f,
		9.099997f,
		4.200000f,
		8.399997f,
		7.699997f,
		6.999997f,
		6.299997f,
		5.599998f,
		4.899998f,
		4.199998f,
		3.499998f,
		2.799998f,
		2.099998f,
		1.399998f,
		0.699998f,
		-0.700000f,
		-1.400000f,
		-2.100000f,
		-2.800000f,
		-3.500000f,
		-4.200000f,
		-4.900000f,
		-5.599999f,
		-6.299999f,
		-6.999999f,
		-7.699999f,
		-8.399999f,
		-9.099998f,
		-9.799998f,
		-10.499998f,
		-11.199998f,
		-11.899998f,
		-12.599998f,
		-13.299997f,
		-13.999997f,
		-14.699997f,
		-15.399997f,
		-16.099997f,
		-16.799997f,
		-17.499998f,
		-18.199999f,
		-18.900000f,
		-19.600000f,
		-20.300001f,
		-21.000002f,
		-21.700003f,
		-22.400003f,
		-23.100004f,
		-23.800005f,
		1.399998f,
		0.699998f,
		-0.000002f,
		-0.700002f,
		-1.400002f,
		-2.100002f,
		-2.800002f,
		-3.500002f,
		-4.200002f,
		-4.900002f,
		-5.600002f,
		-6.300002f,
		-7.000001f,
		-7.700001f,
		-8.400002f,
		-7.700002f,
		-7.000002f,
		-6.300002f,
		-5.600002f,
		-4.900002f,
		-4.200003f,
		-3.500003f,
		4.900000f,
		5.599999f,
		6.299999f,
		6.999999f,
		7.699999f,
		8.399999f,
		-2.800003f,
		-2.100003f,
		-2.800003f,
		-24.500006f,
		-25.200006f,
		-25.900007f,
		-26.600008f,
		-27.300009f,
		-28.000010f,
		-28.700010f,
		7.899999f,
		-3.500003f,
		-4.200003f,
		-4.900002f,
		-5.600002f,
		-6.300002f,
		-7.000002f,
		-7.700002f,
		-8.400002f,
		-9.100001f,
		-9.800001f,
		7.399999f,
		8.099998f,
		8.799998f,
		9.499998f,
		-25.900007f,
		-26.600008f,
		-25.900007f,
		-25.200006f,
		-24.500006f,
		-23.800005f,
		-23.100004f,
		-22.400003f,
		-21.700003f,
		-21.000002f,
		-20.300001f,
		-19.600000f,
		-18.900000f,
		-18.199999f,
		-17.499998f,
		-16.799997f,
		-16.099997f,
		-15.399997f,
		-14.699997f,
		-13.999997f,
		-13.299997f,
		-12.599998f,
		-11.899998f,
		-11.199998f,
		-10.499998f,
		-9.799998f,
		-9.099998f,
		-8.399999f,
		-7.699999f,
		-6.999999f,
		-6.299999f,
		-5.599999f,
		-4.900000f,
		-4.200000f,
		-3.500000f,
		-2.800000f,
		-2.100000f,
		-1.400000f,
		-0.700000f,
		0.000000f,
		0.700000f,
		1.400000f,
		2.100000f,
		2.800000f,
		3.500000f,
		4.200000f,
		4.900000f,
		5.600000f,
		6.300000f,
		7.000000f,
		7.699999f,
		8.400000f,
		9.099999f,
		9.799999f,
		10.499999f,
		11.199999f,
		11.899999f,
		12.599998f,
		13.299998f,
		13.999998f,
		-10.500001f,
		-11.200001f,
		-11.900001f,
		-12.600000f,
		-13.300000f,
		-14.000000f,
		-14.700000f,
		-15.400000f,
		-16.100000f,
		-16.800001f,
		-17.500002f,
		-18.200003f,
		-18.900003f,
		-19.600004f,
		-20.300005f,
		-21.000006f,
		-21.700006f,
		-22.400007f,
		-23.100008f,
		-23.800009f,
		-24.500010f,
		-25.200010f,
		-25.900011f,
		-26.600012f,
		14.699998f,
		15.399998f,
		16.099998f,
		16.799999f,
		17.500000f,
		18.200001f,
		18.900002f,
		19.600002f,
		20.300003f,
		21.000004f,
		21.700005f,
		22.400005f,
		23.100006f,
		-27.300013f,
		-28.000013f,
		-28.700014f,
		-29.400015f,
		-30.100016f,
		-30.800016f,
		-31.500017f,
		-32.200016f,
		-32.900017f,
		-33.600018f,
		-34.300018f,
		-35.000019f,
		-35.700020f,
		-36.400021f,
		-37.100021f,
		-37.800022f,
		-38.500023f,
		-39.200024f,
		-39.900024f,
		-40.600025f,
		-41.300026f,
		-42.000027f,
		-42.700027f,
		-43.400028f,
		-44.100029f,
		-44.800030f,
		-45.500031f,
		-46.200031f,
		-46.900032f,
		-47.600033f,
		-48.300034f,
		-49.000034f,
		-48.300034f,
		23.800007f,
		24.500008f,
		25.200008f,
		25.900009f,
		26.600010f,
		27.300011f,
		28.000011f,
		28.700012f,
		29.400013f,
		30.100014f,
		-28.000010f,
		-27.300009f,
		-26.600008f,
		-25.900007f,
		-25.200006f,
		-24.500006f,
		-23.800005f,
		-23.100004f,
		-22.400003f,
		-21.700003f,
		-21.000002f,
		-20.300001f,
		-19.600000f,
		-18.900000f,
		-18.199999f,
		-17.499998f,
		-16.799997f,
		-16.099997f,
		-15.399997f,
		-14.699997f,
		-13.999997f,
		-13.299997f,
		-12.599998f,
		-11.899998f,
		-11.199998f,
		-10.499998f,
		-9.799998f,
		-9.099998f,
		-8.399999f,
		-7.699999f,
		-6.999999f,
		-6.299999f,
		-5.599999f,
		-4.900000f,
		-4.200000f,
		-3.500000f,
		-2.800000f,
		-2.100000f,
		-1.400000f,
		-0.700000f,
		0.000000f,
		0.700000f,
		1.400000f,
		2.100000f,
		2.800000f,
		3.500000f,
		4.200000f,
		4.900000f,
		5.600000f,
		6.300000f,
		7.000000f,
		7.699999f,
		8.400000f,
		9.099999f,
		9.799999f,
		10.499999f,
		11.199999f,
		11.899999f,
		12.599998f,
		13.299998f,
		13.999998f,
		14.699998f,
		15.399998f,
		14.699998f,
		13.999998f,
		13.299998f,
		12.599998f,
		11.899999f,
		11.199999f,
		10.499999f,
		9.799999f,
		9.099999f,
		8.400000f,
		7.700000f,
		7.000000f,
		6.300000f,
		5.600000f,
		4.900001f,
		4.200001f,
		3.500001f,
		2.800001f,
		2.100001f,
		1.400001f,
		0.700001f,
		0.000001f,
		-0.699999f,
		-1.399999f,
		-2.099999f,
		-2.799999f,
		-3.500000f,
		-4.199999f,
		-4.899999f,
		-5.599999f,
		-6.299999f,
		-6.999999f,
		-7.699998f,
		-8.399999f,
		-9.099998f,
		-9.799998f,
		-10.499998f,
		-11.199998f,
		-11.899998f,
		-12.599998f,
		-13.299997f,
		-13.999997f,
		-14.699997f,
		-15.399997f,
		-16.099997f,
		-16.799997f,
		-17.499998f,
		-18.199999f,
		-18.900000f,
		-19.600000f,
		-20.300001f,
		-21.000002f,
		-21.700003f,
		-22.400003f,
		-23.100004f,
		-23.800005f,
		-24.500006f,
		-25.200006f,
		-25.900007f,
		-26.600008f,
		-27.300009f,
		-28.000010f,
		-28.700010f,
		-29.400011f,
		-30.100012f,
		-30.800013f,
		-31.500013f,
		-32.200012f,
		-32.900013f,
		-33.600014f,
		-34.300014f,
		-35.000015f,
		-35.700016f,
		-36.400017f,
		-37.100018f,
		-37.800018f,
		-38.500019f,
		-39.200020f,
		-39.900021f,
		-40.600021f,
		-41.300022f,
		-42.000023f,
		-42.700024f,
		-43.400024f,
		-44.100025f,
		-44.800026f,
		-45.500027f,
		-46.200027f,
		-46.900028f,
		-47.600029f,
		-48.300030f,
		-49.000031f,
		-49.700031f,
		-49.000031f,
		-48.300030f,
		-47.600029f,
		-46.900028f,
		-46.200027f,
		-45.500027f,
		-45.800026f,
		-45.100025f,
		-45.400024f,
		-45.700024f,
		-45.000023f,
		-45.300022f,
		-45.600021f,
		-45.900021f,
		-45.200020f,
		-45.500019f,
		-45.800018f,
		-45.100018f,
		-45.400017f,
		-45.700016f,
		-45.000015f,
		-45.300014f,
		-45.600014f,
		-45.900013f,
		-45.200012f,
		-45.500011f,
		8.999998f,
		8.499998f,
		7.999998f,
		8.699998f,
		-49.000034f,
		-49.700035f,
		-50.400036f,
		-51.100037f,
		-51.800037f,
		-52.500038f,
		-53.200039f,
		-53.900040f,
		-54.600040f,
		-55.300041f,
		-56.000042f,
		-55.300041f,
		-54.600040f,
		-53.900040f,
		30.800014f,
		31.500015f,
		32.200016f,
		32.900017f,
		33.600018f,
		34.300018f,
		35.000019f,
		35.700020f,
		36.400021f,
		37.100021f,
		37.800022f
	};
	GLint valueType[700] = {
		EYEY,
		EYEY,
		EYEY,
		EYEX,
		EYEX,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEY,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEY,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEY,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEY,
		EYEY,
		EYEY,
		EYEY,
		EYEY,
		EYEY,
		EYEX,
		EYEX,
		EYEX,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		EYEY,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEY,
		EYEY,
		EYEY,
		EYEY,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		YROTATE,
		EYEY,
		EYEY,
		EYEY,
		EYEY,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEX,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ,
		EYEZ
	};
}Positions;

typedef struct POS
{
	GLfloat x, y, z;
}Pos;

typedef struct COLOR
{
	GLfloat r, g, b;
}Color;

typedef struct VERTICES
{
	Pos pos;
	Color color;
}Vertices;

typedef struct CAMERA
{
	GLfloat eyex, eyey, eyez;
}Camera;

int indices[10000000];
Camera camera;

RAINDROP raindrops[RAINDROPS];
float gzDepth = -40.0;
float gGravity = -1.8;

#define M 1000
#define N 1000

GLUquadric *quadric;
Vertices vertices[M * N];

Positions positions;


//Prototype Of WndProc() declared Globally
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//Global variable declarations
int k = 0;
HWND ghwnd = NULL;
HDC ghdc = NULL;
HGLRC ghrc = NULL;

float dx = 0.2f;
float dy = 0.2f;
float dz = 0.2f;
GLfloat yRotate = 0.0f;
GLfloat xRotate = 0.0f;
FILE* fptr;

DWORD dwStyle;
WINDOWPLACEMENT wpPrev = { sizeof(WINDOWPLACEMENT) };

bool gbActiveWindow = false;
bool gbEscapeKeyIsPressed = false;
bool gbFullscreen = false;

void display(void);
void resize(int width, int height);

extern GLint nBranches;

//main()
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	//function prototype
	void initialize(void);
	void uninitialize(void);

	srand(time(NULL));

	//variable declaration
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szClassName[] = TEXT("RTROGL");
	bool bDone = false;

	//code
	//initializing members of struct WNDCLASSEX
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.lpfnWndProc = WndProc;
	wndclass.lpszClassName = szClassName;
	wndclass.lpszMenuName = NULL;

	//Registering Class
	RegisterClassEx(&wndclass);

	//Create Window
	hwnd = CreateWindowEx(WS_EX_APPWINDOW,
		szClassName,
		TEXT("OpenGL Fixed Function Pipeline Using Native Windowing : First Window"),
		WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_VISIBLE,
		0,
		0,
		WIN_WIDTH,
		WIN_HEIGHT,
		NULL,
		NULL,
		hInstance,
		NULL);

	ghwnd = hwnd;

	//initialize
	initialize();

	ShowWindow(hwnd, SW_SHOW);
	SetForegroundWindow(hwnd);
	SetFocus(hwnd);

	//Message Loop
	while (bDone == false)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
				bDone = true;
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{
			if (gbActiveWindow == true)
			{
				if (gbEscapeKeyIsPressed == true)
					bDone = true;
				display();
			}
		}
	}

	uninitialize();
	return((int)msg.wParam);
}

//WndProc()
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	//function prototype
	void display(void);
	void resize(int, int);
	void ToggleFullscreen(void);
	void uninitialize(void);

	//code
	switch (iMsg)
	{
	case WM_ACTIVATE:
		if (HIWORD(wParam) == 0)
			gbActiveWindow = true;
		else
			gbActiveWindow = false;
		break;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
			gbEscapeKeyIsPressed = true;
			break;
		case 0x46: //for 'f' or 'F'
			if (gbFullscreen == false)
			{
				ToggleFullscreen();
				gbFullscreen = true;
			}
			else
			{
				ToggleFullscreen();
				gbFullscreen = false;
			}
			break;
		case 0x5A:
			camera.eyez -= 0.7f;
			//fprintf(fptr, "eyez = %f\n", camera.eyez);
			break;
		case 0x53:
			camera.eyez += 0.7f;
			//fprintf(fptr, "eyez = %f\n", camera.eyez);
			break;
		case 0x52:
			yRotate += 0.7f;
			//fprintf(fptr, "yRotate = %f\n", yRotate);
			break;
		case 0x45:
			yRotate -= 0.7f;
			//fprintf(fptr, "yRotate = %f\n", yRotate);
			break;
		case 0x44:
			xRotate += 0.7f;
			//fprintf(fptr, "xRotate = %f\n", xRotate);
			break;
		case 0x43:
			xRotate -= 0.7f;
			//fprintf(fptr, "xRotate = %f\n", xRotate);
			break;
		case VK_LEFT:
			camera.eyex -= 0.7f;
			//fprintf(fptr, "eyex = %f\n", camera.eyex);
			break;
		case VK_RIGHT:
			camera.eyex += 0.7f;
			//fprintf(fptr, "eyex = %f\n", camera.eyex);
			break;
		case VK_UP:
			camera.eyey += 0.7f;
			//fprintf(fptr, "eyey = %f\n", camera.eyey);
			break;
		case VK_DOWN:
			camera.eyey -= 0.5f;
			//fprintf(fptr, "eyey = %f\n", camera.eyey);
			break;

		default:
			break;
		}
		break;
	case WM_LBUTTONDOWN:
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		break;
	}
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}

void ToggleFullscreen(void)
{
	//variable declarations
	MONITORINFO mi;

	//code
	if (gbFullscreen == false)
	{
		dwStyle = GetWindowLong(ghwnd, GWL_STYLE);
		if (dwStyle & WS_OVERLAPPEDWINDOW)
		{
			mi = { sizeof(MONITORINFO) };
			if (GetWindowPlacement(ghwnd, &wpPrev) && GetMonitorInfo(MonitorFromWindow(ghwnd, MONITORINFOF_PRIMARY), &mi))
			{
				SetWindowLong(ghwnd, GWL_STYLE, dwStyle & ~WS_OVERLAPPEDWINDOW);
				SetWindowPos(ghwnd, HWND_TOP, mi.rcMonitor.left, mi.rcMonitor.top, mi.rcMonitor.right - mi.rcMonitor.left, mi.rcMonitor.bottom - mi.rcMonitor.top, SWP_NOZORDER | SWP_FRAMECHANGED);
				resize(mi.rcMonitor.right - mi.rcMonitor.left, mi.rcMonitor.bottom - mi.rcMonitor.top);
			}
		}
		ShowCursor(FALSE);
	}

	else
	{
		//code
		SetWindowLong(ghwnd, GWL_STYLE, dwStyle | WS_OVERLAPPEDWINDOW);
		SetWindowPlacement(ghwnd, &wpPrev);
		SetWindowPos(ghwnd, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOOWNERZORDER | SWP_NOZORDER | SWP_FRAMECHANGED);
		resize(WIN_WIDTH, WIN_HEIGHT);
		ShowCursor(TRUE);
	}

}

void initLight()
{
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);


	//GLfloat light_pos[] = { 0.0f, 1.0f, 0.0f, 1.0f };
	//GLfloat light_Ka[] = { 0.5f, 0.5f, 0.5f, 1.0f };
	//GLfloat light_Kd[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	//GLfloat light_Ks[] = { 1.0f, 1.0f, 1.0f, 1.0f };

	////glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
	//glLightfv(GL_LIGHT0, GL_AMBIENT, light_Ka);
	//glLightfv(GL_LIGHT0, GL_DIFFUSE, light_Kd);
	//glLightfv(GL_LIGHT0, GL_SPECULAR, light_Ks);

	//GLfloat material_Ka[] = { 0.5f, 0.5f, 0.5f, 0.0f };
	//GLfloat material_Kd[] = { 0.3f, 0.3f, 0.3f, 0.0f };
	//GLfloat material_Ks[] = { 0.5f, 0.5f, 0.5f, 0.0f };
	//GLfloat material_Ke[] = { 0.5f, 0.5f, 0.5f, 0.0f };
//	GLfloat material_Se = 1.0f;

	//glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Ka);
	//glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Kd);
	//glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Ks);
	//glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, material_Ke);
	//glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, material_Se);

	return;
}


float getHeight(float x, float z)
{
	return 0.3f * (z * sinf(0.1f * x) + x * cosf(0.1f*z));
}

void drawTerrain(int m, int n)
{
	
	float halfWidth = (n - 1) * dx * 0.5f;
	float halfDepth = (m - 1) * dx * 0.5f;

	for (int i = 0; i < m; ++i)
	{
		float z = halfDepth - i * dz;
		for (int j = 0; j < n; ++j)
		{
			float x = -halfWidth + j * dx;

			float y = 0.0f;
			if (i < 500 && j < 500)
			{
				y = 0.1f;
			}
			else
			{
				y = getHeight(x, z);
			}
			//float y = -0.1f;;

			vertices[i * n + j].pos.x = x;
			vertices[i * n + j].pos.y = y;
			vertices[i * n + j].pos.z = z;

			if (y < -10.0f)
			{
				vertices[i*n + j].color.r = 1.0f;
				vertices[i*n + j].color.g = 0.96f;
				vertices[i*n + j].color.b = 0.62f;
			}
			else if (y < 5.0f)
			{
				vertices[i*n + j].color.r = 0.48f;
				vertices[i*n + j].color.g = 0.77f;
				vertices[i*n + j].color.b = 0.46f;
			}
			else if (y < 12.0f)
			{
				vertices[i*n + j].color.r = 0.1f;
				vertices[i*n + j].color.g = 0.48f;
				vertices[i*n + j].color.b = 0.19f;
			}
			else if (y < 20.0f)
			{
				vertices[i*n + j].color.r = 0.7f;
				vertices[i*n + j].color.g = 0.7f;
				vertices[i*n + j].color.b = 0.34f;
			}
			else
			{
				vertices[i*n + j].color.r = 1.0f;
				vertices[i*n + j].color.g = 1.0f;
				vertices[i*n + j].color.b = 1.0f;
			}
		//	fprintf(fptr, "x = %f\n", x);
		}
	}
}

void calculateIndices()
{
	for (int i = 0; i < M - 1; ++i)
	{
		for (int j = 0; j < N - 1; ++j)
		{
			indices[k] = i * N + j;
			indices[k + 1] = i * N + j + 1;
			indices[k + 2] = (i + 1)* N + j;

			indices[k + 3] = (i + 1) * N + j;
			indices[k + 4] = i * N + j + 1;
			indices[k + 5] = (i + 1) * N + j + 1;

			k += 6;
		}
	}
}

void initialize(void)
{
	//function prototypes
	void resize(int, int);

	//variable declarations
	PIXELFORMATDESCRIPTOR pfd;
	int iPixelFormatIndex;

	camera.eyex = 0.0f;
	camera.eyey = 0.0f;
	camera.eyez = 0.0f;

//	fopen_s(&fptr,"CameraMoments.txt", "w");

	//code
	ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));

	//Initialization of structure 'PIXELFORMATDESCRIPTOR'
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 32;
	pfd.cRedBits = 8;
	pfd.cGreenBits = 8;
	pfd.cBlueBits = 8;
	pfd.cAlphaBits = 8;

	ghdc = GetDC(ghwnd);

	iPixelFormatIndex = ChoosePixelFormat(ghdc, &pfd);
	if (iPixelFormatIndex == 0)
	{
		ReleaseDC(ghwnd, ghdc);
		ghdc = NULL;
	}

	if (SetPixelFormat(ghdc, iPixelFormatIndex, &pfd) == FALSE)
	{
		ReleaseDC(ghwnd, ghdc);
		ghdc = NULL;
	}

	ghrc = wglCreateContext(ghdc);
	if (ghrc == NULL)
	{
		ReleaseDC(ghwnd, ghdc);
		ghdc = NULL;
	}

	if (wglMakeCurrent(ghdc, ghrc) == FALSE)
	{
		wglDeleteContext(ghrc);
		ghrc = NULL;
		ReleaseDC(ghwnd, ghdc);
		ghdc = NULL;
	}

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	drawTerrain(M, N);
	calculateIndices();

	if (!ReadTreeData()) {
		/* issue warning and exit */
		printf("Unable to read the data from the specified file");
		/*exit(0);*/
	}


	for (size_t i = 0; i < RAINDROPS; i++)
	{
		initraindrops(i);
	}

	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);
	glDepthFunc(GL_LEQUAL);
	glDepthRange(0.0f, 1.0f);
	//glDisable(GL_BLEND);
	//glDisable(GL_ALPHA_TEST);
//	initLight();
	//glCullFace(GL_FRONT_AND_BACK);

	//glEnable(GL_TEXTURE_2D);
	//LoadTexture(IMAGE_NAME);
	quadric = gluNewQuadric();

	DrawLeaves();
	GenerateTree();

	resize(WIN_WIDTH, WIN_HEIGHT);
}



void display(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	//glClearDepth(1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);

	/*glLoadIdentity();
	gluLookAt(0.0f, 5.0f, -15.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

	glTranslatef(0.0f, -5.5f, 0.0f);*/
//	glRotatef(sceneAngle, 0.0f, 1.0f, 0.0f);

	//DrawTree();
	//SwapBuffers(ghdc);
	//return;
	static GLfloat stEyex = 0.0f, stEyey = 2.0f, stEyez = 0.0f ;

	static int cameraIterator = 0;
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//glTranslatef(0.0f, 0.0f, -3.0f);
	//gluLookAt(vertices[cameraIterator].pos.x, 
	//		  vertices[cameraIterator].pos.y + 3.0f, 
	//	      vertices[cameraIterator].pos.z,
	//	      0.0, 0.0, 0.0, 0.0f, 1.0f, 0.0f);

	if (cameraIterator < 692)
	{
		switch (positions.valueType[cameraIterator])
		{
		case EYEX:
			gluLookAt(positions.values[cameraIterator],
				stEyey,
				stEyez,
				positions.values[cameraIterator] + 0.1f,
				stEyey,
				stEyez, 0.0f, 1.0f, 0.0f);
			stEyex = positions.values[cameraIterator];
			break;
		case EYEY:
			gluLookAt(stEyex,
				positions.values[cameraIterator],
				stEyez,
				stEyex + 0.1f,
				positions.values[cameraIterator],
				stEyez, 0.0f, 1.0f, 0.0f);
			stEyey = positions.values[cameraIterator];
			break;
		case EYEZ:
			gluLookAt(stEyex,
				stEyey,
				positions.values[cameraIterator],
				stEyex + 0.1f,
				stEyey,
				positions.values[cameraIterator], 0.0f, 1.0f, 0.0f);
			stEyez = positions.values[cameraIterator];
			break;
		case YROTATE:
			gluLookAt(stEyex,
				stEyey,
				stEyez,
				stEyex + 0.1f,
				stEyey,
				stEyez, 0.0f, 1.0f, 0.0f);
			glRotatef(positions.values[cameraIterator], 0.0f, 1.0f, 0.0f);
			break;
		case XROTATE:
			gluLookAt(stEyex,
				stEyey,
				stEyez,
				stEyex + 0.1f,
				stEyey,
				stEyez, 0.0f, 1.0f, 0.0f);
			glRotatef(positions.values[cameraIterator], 1.0f, 0.0f, 0.0f);
			break;
		}
	}
	else
	{
		gluLookAt(stEyex,
			stEyey,
			stEyez,
			stEyex + 0.1f,
			stEyey,
			stEyez, 0.0f, 1.0f, 0.0f);
	}
	if (cameraIterator < 692)
	{
		cameraIterator++;;
	}
	else
	{
		cameraIterator = 700;
	}

	/*glColor3f(1.0f, 1.0f, 1.0f);
	glPointSize(10.0f);
	glBegin(GL_POINTS);
		glVertex3f(0.0f, 0.0f, 0.0f);
	glEnd();
	*/
	
	//gluLookAt(camera.eyex,
	//	camera.eyey,
	//	camera.eyez,
	//	camera.eyex + 0.1,
	//	camera.eyey,
	//	camera.eyez, 0.0f, 1.0f, 0.0f);
	//
	//glRotatef(xRotate, 1.0f, 0.0f, 0.0f);
	//
	//glRotatef(yRotate, 0.0f, 1.0f, 0.0f);

	//glColor3f(0.0f, 0.01f, 0.3f);
	glBegin(GL_QUADS);
		glColor3f(0.0f, 0.0f, 0.7f);
		glVertex3f(-200.0f, 400.0f, 200.0f);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3f(-200.0f, -200.0f, 200.0f);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3f(200.0f, -200.0f, 200.0f);
		glColor3f(0.0f, 0.0f, 0.7f);
		glVertex3f(200.0f, 400.0f, 200.0f);
	glEnd();

	glBegin(GL_QUADS);
		glColor3f(0.0f, 0.0f, 0.7f);
		glVertex3f(-200.0f, 400.0f, 200.0f);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3f(-200.0f, -200.0f, 200.0f);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3f(-200.0f, -200.0f, -200.0f);
		glColor3f(0.0f, 0.0f, 0.7f);
		glVertex3f(-200.0f, 400.0f, -200.0f);
	glEnd();

	glBegin(GL_QUADS);
		glColor3f(0.0f, 0.0f, 0.7f);
		glVertex3f(200.0f, 400.0f, 200.0f);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3f(200.0f, -200.0f, 200.0f);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3f(200.0f, -200.0f, -200.0f);
		glColor3f(0.0f, 0.0f, 0.7f);
		glVertex3f(200.0f, 400.0f, -200.0f);
	glEnd();

	glBegin(GL_QUADS);
		glColor3f(0.0f, 0.0f, 0.7f);
		glVertex3f(-200.0f, 400.0f, -200.0f);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3f(-200.0f, -200.0f, -200.0f);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3f(200.0f, -200.0f, -200.0f);
		glColor3f(0.0f, 0.0f, 0.7f);
		glVertex3f(200.0f, 400.0f, -200.0f);
	glEnd();
	//glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLES);
		for (int i = 0; i < k-1; i++)
		{
			glColor4f(vertices[indices[i]].color.r, vertices[indices[i]].color.g, vertices[indices[i]].color.b, 1.0f);
			glVertex3f(vertices[indices[i]].pos.x, vertices[indices[i]].pos.y, vertices[indices[i]].pos.z);
		}
	glEnd();


	glLoadIdentity();
	if (cameraIterator == 700)
	{
//		glTranslatef(camera.eyex,
//				camera.eyey,
//				camera.eyez);
		glColor3f(0.9, 0.9, 1.0);
		glTranslatef(2.0f, -3.0f, -15.0f);
		glBegin(GL_LINES);
		for (size_t i = 0; i < RAINDROPS; i++)
		{
			float x = raindrops[i].x;
			float y = raindrops[i].y;
			float z = raindrops[i].z;

			glVertex3f(x, y, z + gzDepth);
			glVertex3f(x, y + 0.5, z + gzDepth);

			raindrops[i].y += raindrops[i].speed / (2.0 * 1000);
			raindrops[i].speed += gGravity;
			raindrops[i].scope -= raindrops[i].scopeLife;

			// for continiuos rain init it again
			if (raindrops[i].scope< 0.0)
				initraindrops(i);
		}
		glEnd();
		if (nBranches < 7000)
		{
			GenerateTree();
			nBranches++;
		}
		DrawTree();

		if (nBranches > 200)
		{
			glTranslatef(-0.5f, -2.0f, 0.0f);
			drawBoy(0.15, 0.20, -0.10, red, blue);
		}
	}
	//k = 0;
	SwapBuffers(ghdc);
}

void resize(int width, int height)
{
	//code
	if (height == 0)
		height = 1;
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 1000.0f);
}

void uninitialize(void)
{
	//UNINITIALIZATION CODE

	if (gbFullscreen == true)
	{
		dwStyle = GetWindowLong(ghwnd, GWL_STYLE);
		SetWindowLong(ghwnd, GWL_STYLE, dwStyle | WS_OVERLAPPEDWINDOW);
		SetWindowPlacement(ghwnd, &wpPrev);
		SetWindowPos(ghwnd, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOOWNERZORDER | SWP_NOZORDER | SWP_FRAMECHANGED);

		ShowCursor(TRUE);

	}

	wglMakeCurrent(NULL, NULL);

	wglDeleteContext(ghrc);
	ghrc = NULL;

	ReleaseDC(ghwnd, ghdc);
	ghdc = NULL;

	DestroyWindow(ghwnd);
	ghwnd = NULL;
	//fclose(fptr);
}
