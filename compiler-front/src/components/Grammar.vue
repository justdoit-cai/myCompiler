<template>
    <el-container>
        <el-aside width="20%">
            <span>输入文法文件</span>
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
            <span>输入Lex文件</span>
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
            <el-button type="primary" @click="handleCompileGrammar">开始编译</el-button>
        </el-aside>
        <div style="width: 1px; background-color: lightskyblue; margin: 0 10px;"></div>
        <el-main style="padding-top: 0;padding-left: 0">
            <el-header>
                <el-row :gutter="50">
                    <el-col :span="6">
                        <el-button color="#626aef" style="width: 250px;"
                                   @click="showFFSet=true;showLR0=false;showSLR1=false">
                            显示First集合和Follow集合
                        </el-button>
                    </el-col>
                    <el-col :span="6">
                        <el-button color="#626aef" style="width: 250px;"
                                   @click="showLR0=true;showFFSet=false;showSLR1=false">
                            显示LR(0)DFA图
                        </el-button>
                    </el-col>
                    <el-col :span="6">
                        <el-button color="#626aef" style="width: 250px;"
                                   @click="showSLR1=true;showFFSet=false;showLR0=false">
                            显示SLR(1)分析表
                        </el-button>
                    </el-col>
                    <el-col :span="6">
                        <el-button color="#626aef" style="width: 250px;" @click="handleOutputTree">
                            生成语法树
                        </el-button>
                    </el-col>
                </el-row>
            </el-header>
            <div v-show="showFFSet">
                <el-card style="width: 100%;">
                    <el-table
                            :data="data1"
                            stripe
                            border
                            style="width: 100%">
                        <el-table-column
                                prop="char"
                                label="字符"
                                width="80">
                        </el-table-column>
                        <el-table-column
                                prop="firstSet"
                                label="first集合"
                                width="450">
                        </el-table-column>
                        <el-table-column
                                prop="followSet"
                                label="follow集合"
                                width="450">
                        </el-table-column>
                    </el-table>
                </el-card>
            </div>
            <div v-show="showLR0">
                <el-card style="width: 100%;">
                    <div id="myGraph" style="height: 950px"></div>
                </el-card>
            </div>
            <div v-show="showSLR1">
                <el-card style="width: 100%;">
                    <el-table
                            :data="data3"
                            stripe
                            border
                            style="width: 100%">
                        <el-table-column
                                label="状态"
                                type="index"
                                :index="indexMethod"
                                width="80">
                        </el-table-column>
                        <el-table-column
                                label="输入"
                                width="450">
                            <template v-for="(item) in slrTableHead1">
                                <el-table-column :prop="item" :label="item"></el-table-column>
                            </template>
                        </el-table-column>
                        <el-table-column
                                label="Goto"
                                width="450">
                            <template v-for="(item) in slrTableHead2">
                                <el-table-column :prop="item" :label="item"></el-table-column>
                            </template>
                        </el-table-column>
                    </el-table>
                </el-card>
            </div>
            <div v-show="showOutputTree">
                <vue-json-pretty :highlightMouseoverNode="true"
                                 :collapsedOnClickBrackets="true"
                                 path="res" :data="grammarTree">
                </vue-json-pretty>
            </div>
        </el-main>
    </el-container>
</template>

<script setup lang="ts">
import {onMounted, ref} from 'vue'
import VueJsonPretty from 'vue-json-pretty';
import 'vue-json-pretty/lib/styles.css';
const fs = require('fs');
import {ElMessage, genFileId} from 'element-plus'
import type {UploadInstance, UploadProps, UploadRawFile} from 'element-plus'
import {UploadFilled} from '@element-plus/icons-vue'

const upload = ref<UploadInstance>()
import {Network} from "vis-network";
import {DataSet} from "vis-data/peer/umd/vis-data.min";
const spawnSync = require("child_process").spawnSync
const spawn = require("child_process").spawn
const inputGrammar = ref("");
const inputGrammarPath = ref("")
const inputLexPath = ref("")
const output = ref(null)
const showFFSet = ref(false)
const showLR0 = ref(false)
const showSLR1 = ref(false)
const showOutputTree = ref(false)
let data1 = ref([]); // first和follow集合
let data2 = ref(null); // lr0的dfa图，但是后面其实没用到
let data3 = ref([]); // slr1分析表
let slrTableHead1 = ref([]); // action表头
let slrTableHead2 = ref([]); // goto表头
let grammarTree = ref(null) // 语法树
function handleChangeFile1(file) {
    console.log("handleChangeFile")
    console.log(file.raw.path)
    fs.readFile(file.raw.path, (err, data) => {
        if (err) throw err;
        console.log(data.toString())
        inputGrammar.value = data.toString();
        inputGrammarPath.value = file.raw.path;
        ElMessage({
            message: '上传成功',
            type: 'success',
        })
    })
}

function handleRemoveFile1() {
    console.log("handleRemoveFile")
    inputGrammar.value = ""
    inputGrammarPath.value = null;
    ElMessage({
        message: '清除成功',
        type: 'success',
    })
}
function handleChangeFile2(file) {
    console.log("handleChangeFile")
    inputLexPath.value = file.raw.path;
    ElMessage({
        message: '上传成功',
        type: 'success',
    })
}

function handleRemoveFile2() {
    console.log("handleRemoveFile")
    inputLexPath.value = ""
    ElMessage({
        message: '清除成功',
        type: 'success',
    })
}
function handleCompileGrammar() {
    if (inputGrammarPath.value == "" || inputLexPath.value == "") {
        ElMessage({
            message: "输入文法文件和Lex文件后才能进行编译",
            type: "error"
        })
        return
    }
    spawnSync("main.exe", [inputGrammarPath.value, inputLexPath.value], {})
    output.value = JSON.parse(fs.readFileSync("temp_grammar.out"))

    data1.value = output.value["firstAndFollowSet"];
    console.log(data1.value)
    let nodeList = output.value["lr0"]["node"];
    console.log(nodeList)
    let newNodeList = [];
    for (let i = 0; i < nodeList.length; ++i) {
        let text = "";
        for (let j = 0; j < nodeList[i].length; ++j) {
            text += nodeList[i][j].left + "->" + nodeList[i][j].right + "\n";
        }
        text += "状态" + i;
        let node = {
            id: i,
            label: text,
            shape: "box"
        }
        newNodeList.push(node);
    }
    let edgeList = output.value["lr0"]["edge"];
    console.log(edgeList)
    let newEdgeList = [];
    // 给数组对象添加新的属性信息
    edgeList.map((item, index) => {
        newEdgeList.push(Object.assign({}, item, {"arrows": "to"}));
    });
    let visNodeList = new DataSet(newNodeList);
    let visEdgeList = new DataSet(newEdgeList);
    let container = document.getElementById("myGraph");
    let visData = {
        nodes: visNodeList,
        edges: visEdgeList,
    };
    let options = {
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
    }
    let network = new Network(container, visData, options);
    data3.value = output.value["slr1"];
    let tableHead = Object.keys(data3.value[0]);
    let reg = /[A-Z]*/;
    slrTableHead1.value = [];
    slrTableHead2.value = [];
    for (let i = 0; i < tableHead.length; ++i) {
        // 非终结符
        if (reg.test(tableHead[i])) {
            slrTableHead1.value.push(tableHead[i]);
        } else {
            slrTableHead2.value.push(tableHead[i]);
        }
    }
    grammarTree.value = JSON.parse(JSON.stringify(output.value["tree"]))
    showFFSet.value = true;
    showLR0.value = false;
    showSLR1.value = false;
    showOutputTree.value = false;
    ElMessage({
        message: "编译成功",
        type: "success"
    })
}

function handleFFSet() {
    showFFSet.value = true;
    showLR0.value = false;
    showSLR1.value = false;
    showOutputTree.value = false;
}

function handleLR0() {
    showFFSet.value = false;
    showLR0.value = true;
    showSLR1.value = false;
    showOutputTree.value = false;
}

function handleSLR1() {
    showFFSet.value = false;
    showLR0.value = false;
    showSLR1.value = true;
    showOutputTree.value = false;
}

function handleOutputTree() {
    showFFSet.value = false;
    showLR0.value = false;
    showSLR1.value = false;
    showOutputTree.value = true;
}

function indexMethod(index) {
    return index;
}

onMounted(() => {
    console.log("onMounted");
})
</script>

<style>

</style>