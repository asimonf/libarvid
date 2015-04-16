/* frame rate conversion tables*/
#include "libarvid.h"

arvid_line_rate arvid_rate_table[4][RATE_SIZE] = {
{

// mode 0 - 320 pixels width
{304,  50.000000},
{303,  50.166668},
{302,  50.333332},
{301,  50.500000},
{300,  50.650002},
{299,  50.816666},
{298,  50.983334},
{297,  51.150002},
{296,  51.316666},
{295,  51.500000},
{294,  51.666668},
{293,  51.833332},
{292,  52.016666},
{291,  52.183334},
{290,  52.366665},
{289,  52.533333},
{288,  52.716667},
{287,  52.883335},
{286,  53.066666},
{285,  53.250000},
{284,  53.433334},
{283,  53.616665},
{282,  53.799999},
{281,  53.983334},
{280,  54.183334},
{279,  54.366665},
{278,  54.549999},
{277,  54.750000},
{276,  54.933334},
{275,  55.133335},
{274,  55.333332},
{273,  55.533333},
{272,  55.733334},
{271,  55.933334},
{270,  56.133335},
{269,  56.333332},
{268,  56.533333},
{267,  56.733334},
{266,  56.950001},
{265,  57.150002},
{264,  57.366665},
{263,  57.583332},
{262,  57.783333},
{261,  58.000000},
{260,  58.216667},
{259,  58.433334},
{258,  58.666668},
{257,  58.883335},
{256,  59.099998},
{255,  59.333332},
{254,  59.549999},
{253,  59.783333},
{252,  60.016666},
{251,  60.250000},
{250,  60.483334},
{249,  60.716667},
{248,  60.950001},
},


{ // mode 1 - 256 pixels width
{304, 50.733334},
{303, 50.883335},
{302, 51.049999},
{301, 51.216667},
{300, 51.383335},
{299, 51.549999},
{298, 51.716667},
{297, 51.883335},
{296, 52.066666},
{295, 52.233334},
{294, 52.400002},
{293, 52.583332},
{292, 52.750000},
{291, 52.933334},
{290, 53.099998},
{289, 53.283333},
{288, 53.466667},
{287, 53.650002},
{286, 53.833332},
{285, 54.016666},
{284, 54.200001},
{283, 54.383335},
{282, 54.566666},
{281, 54.766666},
{280, 54.950001},
{279, 55.150002},
{278, 55.333332},
{277, 55.533333},
{276, 55.733334},
{275, 55.916668},
{274, 56.116665},
{273, 56.316666},
{272, 56.516666},
{271, 56.716667},
{270, 56.933334},
{269, 57.133335},
{268, 57.333332},
{267, 57.549999},
{266, 57.766666},
{265, 57.966667},
{264, 58.183334},
{263, 58.400002},
{262, 58.616665},
{261, 58.833332},
{260, 59.049999},
{259, 59.266666},
{258, 59.500000},
{257, 59.716667},
{256, 59.950001},
{255, 60.166668},
{254, 60.400002},
{253, 60.633335},
{252, 60.866665},
{251, 61.099998},
{250, 61.333332},
{249, 61.583332},
{248, 61.816666},
},

{// mode 2 - 288 pixels width

{304,  50.000000},
{303,  50.166668},
{302,  50.316666},
{301,  50.483334},
{300,  50.650002},
{299,  50.816666},
{298,  50.983334},
{297,  51.150002},
{296,  51.316666},
{295,  51.483334},
{294,  51.650002},
{293,  51.833332},
{292,  52.000000},
{291,  52.166668},
{290,  52.349998},
{289,  52.533333},
{288,  52.700001},
{287,  52.883335},
{286,  53.066666},
{285,  53.250000},
{284,  53.433334},
{283,  53.616665},
{282,  53.799999},
{281,  53.983334},
{280,  54.166668},
{279,  54.349998},
{278,  54.549999},
{277,  54.733334},
{276,  54.933334},
{275,  55.116665},
{274,  55.316666},
{273,  55.516666},
{272,  55.716667},
{271,  55.916668},
{270,  56.116665},
{269,  56.316666},
{268,  56.516666},
{267,  56.733334},
{266,  56.933334},
{265,  57.150002},
{264,  57.349998},
{263,  57.566666},
{262,  57.783333},
{261,  58.000000},
{260,  58.216667},
{259,  58.433334},
{258,  58.650002},
{257,  58.866665},
{256,  59.099998},
{255,  59.316666},
{254,  59.549999},
{253,  59.766666},
{252,  60.000000},
{251,  60.233334},
{250,  60.466667},
{249,  60.700001},
{248,  60.933334},

},

{// mode 3 - 384 pixels width
{304,  49.966667},
{303,  50.133335},
{302,  50.299999},
{301,  50.450001},
{300,  50.616665},
{299,  50.783333},
{298,  50.950001},
{297,  51.116665},
{296,  51.283333},
{295,  51.450001},
{294,  51.633335},
{293,  51.799999},
{292,  51.966667},
{291,  52.150002},
{290,  52.316666},
{289,  52.500000},
{288,  52.666668},
{287,  52.849998},
{286,  53.033333},
{285,  53.216667},
{284,  53.400002},
{283,  53.583332},
{282,  53.766666},
{281,  53.950001},
{280,  54.133335},
{279,  54.316666},
{278,  54.516666},
{277,  54.700001},
{276,  54.900002},
{275,  55.099998},
{274,  55.283333},
{273,  55.483334},
{272,  55.683334},
{271,  55.883335},
{270,  56.083332},
{269,  56.283333},
{268,  56.483334},
{267,  56.700001},
{266,  56.900002},
{265,  57.116665},
{264,  57.316666},
{263,  57.533333},
{262,  57.750000},
{261,  57.966667},
{260,  58.183334},
{259,  58.400002},
{258,  58.616665},
{257,  58.833332},
{256,  59.049999},
{255,  59.283333},
{254,  59.516666},
{253,  59.733334},
{252,  59.966667},
{251,  60.200001},
{250,  60.433334},
{249,  60.666668},
{248,  60.900002},

},


};
