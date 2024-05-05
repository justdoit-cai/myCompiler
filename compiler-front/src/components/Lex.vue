<template>
    <el-container>
        <el-aside width="20%">
            <span>输入正则表达式文件</span>
            <el-upload
                    class="upload-demo"
                    drag
                    action=""
                    :auto-upload="false"
                    :limit="1"
                    :on-change="handleChangeFile1"
                    :on-remove="handleRemoveFile1"
            >
                <el-icon class="el-icon--upload">
                    <upload-filled/>
                </el-icon>
                <div class="el-upload__text">
                    Drop file here or <em>click to upload</em>
                </div>
            </el-upload>
            <span>输入源程序文件</span>
            <el-upload
                class="upload-demo"
                drag
                action=""
                :auto-upload="false"
                :limit="1"
                :on-change="handleChangeFile2"
                :on-remove="handleRemoveFile2"
            >
                <el-icon class="el-icon--upload">
                    <upload-filled/>
                </el-icon>
                <div class="el-upload__text">
                    Drop file here or <em>click to upload</em>
                </div>
            </el-upload>
            <el-button type="primary" @click="handleCompileLex">开始编译</el-button>
        </el-aside>
        <div style="width: 1px; background-color: lightskyblue; margin: 0 10px;"></div>
        <el-main style="padding-top: 0;padding-left: 0">
            <el-row :gutter="20">
                <el-col :span=6>
                    <el-button color="#626aef" style="width: 150px;" @click="handleNFA">
                        显示NFA
                    </el-button>
                </el-col>
                <el-col :span="6">
                    <el-button color="#626aef" style="width: 150px;" @click="handleDFA">
                        显示DFA
                    </el-button>
                </el-col>
                <el-col :span="6">
                    <el-button color="#626aef" style="width: 150px;" @click="handleSimplifyDFA">
                        显示最小化DFA
                    </el-button>
                </el-col>
                <el-col :span="6">
                    <el-button color="#626aef" style="width: 150px;" @click="handleCombinedDFA">
                        显示合并后的DFA
                    </el-button>
                </el-col>
            </el-row>
            <el-row :gutter="20">
                <el-col :span="6">
                    <el-button color="#626aef" style="width: 150px;" @click="handleOutputCode">
                        显示词法分析程序
                    </el-button>
                </el-col>
                <el-col :span="6">
                    <el-button color="#626aef" style="width: 150px;" @click="handleCompileCode">
                        编译词法分析程序
                    </el-button>
                </el-col>
                <el-col :span="6">
                    <el-button color="#626aef" style="width: 150px;" @click="handleExecCode">
                        运行词法分析程序
                    </el-button>
                </el-col>
                <el-col :span="6">
                    <el-button color="#626aef" style="width: 150px;" @click="handleSaveCode">
                        保存当前显示code
                    </el-button>
                </el-col>
            </el-row>
            <div v-show="showGraph" v-for="(value, key, index) in graph">
                <el-card>
                    {{ key }}
                    <el-divider/>
                    <div>
                        <!--                            <el-row>-->
                        <!--                                <span>{{ message }}</span>-->
                        <!--                            </el-row>-->
                        <!--                            <br>-->
                        <div :id="key" style="width: 100%; height: 600px; border: 2px; background-color: #fff;">
                        </div>
                    </div>
                </el-card>
                <br>
            </div>

            <div v-show="showCodeGraph">
                <el-card>
                    <div>
                        <!--                            <el-row>-->
                        <!--                                <span>{{ message }}</span>-->
                        <!--                            </el-row>-->
                        <!--                            <br>-->
                        <div id="combinedDfa" style="width: 100%; height: 600px; border: 2px; background-color: #fff;">
                        </div>
                    </div>
                </el-card>
                <br>
            </div>
            <div v-show="showCode">
                <el-card>
                    <pre><code v-text="code"></code></pre>
                </el-card>
                <br>
            </div>
        </el-main>
    </el-container>
</template>

<script setup lang="ts">
import {onMounted, ref} from 'vue'
const fs = require('fs');
import {ElMessage, genFileId} from 'element-plus'
import type {UploadInstance, UploadProps, UploadRawFile} from 'element-plus'
import {UploadFilled} from '@element-plus/icons-vue'
const spawnSync = require("child_process").spawnSync
const spawn = require("child_process").spawn
const upload = ref<UploadInstance>()
import {Network} from "vis-network";
import {DataSet} from "vis-data/peer/umd/vis-data.min";
const inputLex = ref(""); // 正则表达式文件内容
const inputLexPath = ref(null) // 正则表达式文件路径
const inputCodePath = ref(null) // 源程序文件路径
const outputCodePath = ref("") // 输出的lex文件路径
const output = ref(null)
const graph = ref(null)
const code = ref("")
const showGraph = ref(false)
const showCode = ref(false)
const showCodeGraph = ref(false)
function handleChangeFile1(file) {
    console.log("handleChangeFile")
    console.log(file.raw.path)
    fs.readFile(file.raw.path, (err, data) => {
        if (err) throw err;
        console.log(data.toString())
        inputLex.value = data.toString();
        inputLexPath.value = file.raw.path;
        ElMessage({
            message: '正则表达式文件上传成功',
            type: 'success',
        })
    })
}

function handleRemoveFile1() {
    console.log("handleRemoveFile")
    inputLex.value = ""
    inputLexPath.value = null;
    ElMessage({
        message: '正则表达式文件清除成功',
        type: 'success',
    })
}
function handleChangeFile2(file) {
    console.log("handleChangeFile")
    inputCodePath.value = file.raw.path;
    console.log(inputCodePath.value)
    ElMessage({
        message: '源程序文件上传成功',
        type: 'success',
    })
}

function handleRemoveFile2() {
    console.log("handleRemoveFile")
    inputCodePath.value = null;
    ElMessage({
        message: '源程序文件清除成功',
        type: 'success',
    })
}
function handleCompileLex() {
    console.log("handleCompileLex")
    if (inputLexPath.value === null || inputLex.value === "") {
        ElMessage({
            message: "输入正则表达式文件后才能进行编译",
            type: "error"
        })
        return
    }
    spawn("main.exe", [inputLexPath.value], {})
    fs.readFile("temp_re.out", (err, content) => {
        if (err) throw err;
        console.log(content.toString())
        output.value = JSON.parse(content.toString());
        graph.value = output.value["graph"]
        ElMessage({
            message: "编译成功",
            type: "success"
        })
    })
}

function handleNFA() {
    showGraph.value = true;
    showCode.value = false;
    showCodeGraph.value = false;

    for (let key in graph.value) {
        console.log(key)
        let obj = graph.value[key]["re2nfa"];
        let start = obj['start'];
        let end = obj['end'];
        let nodeList = [];
        let edgeList = obj["edgeList"];
        for (let i = start; i <= end; ++i) {
            let node = {
                id: i,
                label: i.toString()
            }
            nodeList.push(node);
        }

        let newEdgeList = [];
        edgeList.map((item, index) => {
            newEdgeList.push(Object.assign({}, item, {"arrows": "to"}));
        });
        let visNodeList = new DataSet(nodeList);
        let visEdgeList = new DataSet(newEdgeList);
        // 获取容器
        var container = document.getElementById(key);
        // 将数据赋值给vis 数据格式化器
        var visData = {
            nodes: visNodeList,
            edges: visEdgeList
        };
        var options = {
            layout: {
                hierarchical: {
                    direction: "UD",
                },
            },
            physics: {
                hierarchicalRepulsion: {
                    avoidOverlap: 1,
                },
            },
        };
        // 初始化关系图
        var network = new Network(container, visData, options);
    }
    console.log("finish handle nfa")
}

function handleDFA() {
    showGraph.value = true;
    showCode.value = false;
    showCodeGraph.value = false;

    for (let key in graph.value) {
        console.log(key)
        let obj = graph.value[key]["nfa2dfa"];
        let start = obj['start'];
        let end = obj['end']; // DFA的end是数组
        let edgeList = obj["edgeList"];
        let nodeList = obj['nodeList'];
        let newNodeList = [];
        for (let i = start; i < nodeList.length; ++i) {
            let label = i.toString() + ":{" + nodeList[i] + "}";
            let node = {
                id: i,
                label: label
            }
            newNodeList.push(node);
        }

        let newEdgeList = [];
        edgeList.map((item, index) => {
            newEdgeList.push(Object.assign({}, item, {"arrows": "to"}));
        });
        let visNodeList = new DataSet(newNodeList);
        let visEdgeList = new DataSet(newEdgeList);

        // 获取容器
        var container = document.getElementById(key);
        // 将数据赋值给vis 数据格式化器
        var visData = {
            nodes: visNodeList,
            edges: visEdgeList
        };
        var options = {
            layout: {
                hierarchical: {
                    direction: "UD",
                },
            },
            physics: {
                hierarchicalRepulsion: {
                    avoidOverlap: 1,
                },
            },
        };
        // 初始化关系图
        var network = new Network(container, visData, options);
    }
    console.log("finish handle dfa")
    console.log(showGraph.value)

}

function handleSimplifyDFA() {
    showGraph.value = true;
    showCode.value = false;
    showCodeGraph.value = false;

    for (let key in graph.value) {
        let obj = graph.value[key]["simplifiedDfa"];

        let start = obj['start'];
        let end = obj['end'];

        let edgeList = obj['edgeList'];

        let nodeList = [];
        let s = new Set();
        for (let i in edgeList) {
            s.add(edgeList[i].from);
            s.add(edgeList[i].to);
        }
        for (let i of s.values()) { // 注意这里set遍历的方式
            let node = {
                id: i,
                label: i.toString()
            }
            nodeList.push(node);
        }
        let newEdgeList = [];
        edgeList.map((item, index) => {
            newEdgeList.push(Object.assign({}, item, {"arrows": "to"}));
        });
        let visNodeList = new DataSet(nodeList);
        let visEdgeList = new DataSet(newEdgeList);

        // 获取容器
        var container = document.getElementById(key);
        // 将数据赋值给vis 数据格式化器
        var visData = {
            nodes: visNodeList,
            edges: visEdgeList
        };
        var options = {
            layout: {
                hierarchical: {
                    direction: "UD",
                },
            },
            physics: {
                hierarchicalRepulsion: {
                    avoidOverlap: 1,
                },
            },
        };
        // 初始化关系图
        var network = new Network(container, visData, options);
    }
}

function handleCombinedDFA() {
    showCodeGraph.value = true;
    showCode.value = false;
    showGraph.value = false;
    let obj = output.value["code"];
    let edgeList = obj['edgeList'];

    let nodeList = [];
    let s = new Set();
    for (let i in edgeList) {
        s.add(edgeList[i].from);
        s.add(edgeList[i].to);
    }
    for (let i of s.values()) { // 注意这里set遍历的方式
        let node = {
            id: i,
            label: i.toString()
        }
        nodeList.push(node);
    }
    let newEdgeList = [];
    edgeList.map((item, index) => {
        newEdgeList.push(Object.assign({}, item, {"arrows": "to"}));
    });
    let visNodeList = new DataSet(nodeList);
    let visEdgeList = new DataSet(newEdgeList);

    // 获取容器
    var container = document.getElementById("combinedDfa");
    // 将数据赋值给vis 数据格式化器
    var visData = {
        nodes: visNodeList,
        edges: visEdgeList
    };
    var options = {
        layout: {
            hierarchical: {
                direction: "UD",
            },
        },
        physics: {
            hierarchicalRepulsion: {
                avoidOverlap: 1,
            },
        },
    };
    // 初始化关系图
    var network = new Network(container, visData, options);
}

function handleOutputCode() {
    showCode.value = true;
    showGraph.value = false;
    showCodeGraph.value = false;
    code.value = output.value["code"]["code"]
}

function handleCompileCode() {
    fs.writeFile("./temp_lex.cpp", code.value, (err) => {
        if (err)
            console.log(err);
        else {
            console.log("File written successfully\n");
        }
    })
    const proc = spawn("g++", ["temp_lex.cpp", "-o", "lex.exe"], {})
    ElMessage({
        message: '编译成功，生成的可执行程序为lex.exe',
        type: 'success',
    })
}

function handleExecCode() {
    if (inputCodePath.value == null || inputLexPath.value == null) {
        ElMessage({
            message: '输入源程序文件后才能进行词法分析',
            type: 'error',
        })
        return
    }
    const proc = spawn("lex.exe", [inputCodePath.value], {})
    proc.stdout.on('data', function (data) {
        showCode.value = true;
        showGraph.value = false;
        showCodeGraph.value = false;
        code.value = data.toString();
        ElMessage({
            message: '分析成功',
            type: 'success',
        })
    })
}

function handleSaveCode() {
    if (code.value == "") {
        ElMessage({
            message: "当前code为空",
            type: "error"
        })
    }
    let timestamp = (new Date()).valueOf();
    let filename = timestamp + ".txt"
    console.log(filename)
    fs.writeFile(filename, code.value, (err) => {
        if (err) {
            console.log(err);
            ElMessage({
                message: "保存失败: " + err,
                type: "error"
            })
        }
        else {
            ElMessage({
                message: "成功保存至" + filename,
                type: "success"
            })
        }
    });
}



onMounted(() => {
    console.log("onMounted");
})
</script>

<style>

</style>