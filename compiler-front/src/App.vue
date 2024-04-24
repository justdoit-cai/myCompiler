<script setup>
import Grammar from "@/components/Grammar.vue";
import Lex from "@/components/Lex.vue";
import { ref } from 'vue'
const activeName = ref('first')
</script>
<template>
    <el-tabs
        v-model="activeName"
        type="card"
        class="demo-tabs"
    >
        <el-tab-pane label="词法分析" name="first">
            <Lex></Lex>
        </el-tab-pane>
        <el-tab-pane label="文法分析" name="second">
            <Grammar></Grammar>
        </el-tab-pane>
    </el-tabs>
</template>
<style>
.demo-tabs > .el-tabs__content {
    color: #6b778c;
    font-size: 32px;
    font-weight: 600;
    width: 98%;
    position: absolute;
}
* {
    margin: 0;
    padding: 0;
}
</style>
