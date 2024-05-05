const {app, BrowserWindow, dialog, ipcMain, Menu} = require('electron');
const util = require("util");
const exec = util.promisify(require("child_process").exec);
const path = require("path");
const fs = require("fs");

/*隐藏electron的菜单栏*/
Menu.setApplicationMenu(null)

const createWindow = () => {
    const win = new BrowserWindow({
        width: 1600,
        height: 1200,
        webPreferences: {
            // 导入预加载脚本
            // preload: path.join(__dirname, 'preload.js'),
            sandbox: false,
            nodeIntegration: true, //开启true这一步很重要,目的是为了vue文件中可以引入node和electron相关的API
            contextIsolation: false, // 可以使用require方法
            enableRemoteModule: true, // 可以使用remote方法
        }
    })

    win.loadFile('dist/index.html');
    // win.loadURL("http://localhost:5173")
    win.webContents.openDevTools();
}


app.whenReady().then(() => {
    createWindow();
    app.on('activate', () => {
        if (BrowserWindow.getAllWindows().length === 0) {
            createWindow();
        }
    })
})

// 适配mac
app.on('window-all-closed', () => {
    if (process.platform !== 'darwin') {
        app.quit()
    }
})
