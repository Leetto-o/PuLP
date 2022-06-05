# PuLP使用
## 数据的准备
在运行pulp分图工具之前，请先准备一个.adj文件
这个.adj文件是一个32位的二进制文件，文件的每一行由边的始点、终点和label组成（中间没有分隔符）
可以使用binary(32binary.cpp为其源文件)生成这个.adj文件，运行binary时需要输入有2个参数，第一个参数为.e文件的路径，第二个参数为要输出的.adj文件路径及文件名
其中.e文件每一行由边的始点、终点和label组成（中间可由\t,空格将其分开）
例如: ./32binary data.e data.adj
## 使用xtrapulp，提交任务
xtrapulp的主程序在 /home/LAB/hanzy/PuLP/PuLP/xtrapulp/0.2 中
主程序为xtrapulp，运行xtrapulp时需要输入有3个参数，第一个参数是之前生成的.adj文件的路径，第二个参数是要分成子图的个数，第三个参数是最终生成的.part文件
例如: ./xtrapulp data.adj 3 -o data.part
如果图较大，可以申请多个cpu，可以修改pulp.sh中xtrapulp的参数，参数同上，并sbatch pulp.sh提交任务即可
## .part文件说明
.part中将生成一列数字，数字表示对应点所属于的图的标号
# How to use PuLP
## prepare data
Before run the pulp, please prepare a .adj file as input.
The file is a binary file. Each line of the file consists of source node, destination node and label of edge.(without any character among them)
Could run binary(32bianry.cpp as source file) to generate .adj file. Two arguments are needed to run binary. First one is the path of a .e file. The other is the path of .adj file that you want to generate.
.e consists of source node, destination node and label of edge.(Can sperated by \t & space and so on)
For example: ./32binary data.e data.adj
## Run xtrapulp and submit mission
PuLP main program is in /home/LAB/hanzy/PuLP/PuLP/xtrapulp/0.2
The main program is xtrapulp. Three arguments are needed to run xtrapulp. The first one is path of .adj file. The second is the numbers of parts you want to get. The last one is the path of result which is a .part file.
For example: ./xtrapulp data.adj 3 -o data.part
If the graph is too large, could try to apply for multiple cpu. Just modify the arguments(refer to above) that xtrapulp needs in pulp.sh and sbatch pulp.sh to submit mission.
## About .part file
In .part file, the number means which part the edge belongs to. 
