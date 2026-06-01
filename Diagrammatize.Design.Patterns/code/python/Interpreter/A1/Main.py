import tkinter as tk
from tkinter import Frame, Text, Entry, Button, Scrollbar
from language import InterpreterFacade, ExecuteException
from turtle import TurtleCanvas
import sys

class Main(tk.Frame):
    def __init__(self, master=None, title="Interpreter Pattern Sample"):
        super().__init__(master)
        
        # 创建画布（400x400）
        self.canvas = TurtleCanvas(self, 400, 400)
        
        # 创建解释器外观
        self.facade = InterpreterFacade(self.canvas)
        
        # 创建文本输入框，默认命令
        self.programTextField = tk.Entry(self, width=50)
        self.programTextField.insert(0, "program repeat 3 go right go left end end")
        
        # 设置画布的执行器
        self.canvas.set_executor(self.facade)
        
        # 设置布局
        self.setup_ui()
        
        # 绑定事件
        self.bind_events()
        
        # 解析并执行初始程序
        self.parseAndExecute()
    
    def setup_ui(self):
        # 创建主框架
        self.master.title("Interpreter Pattern Sample")
        self.master.geometry("500x500")
        
        # 设置pack布局
        self.pack(fill=tk.BOTH, expand=True)
        
        # 顶部：文本输入框
        self.programTextField.pack(side=tk.TOP, fill=tk.X, padx=5, pady=5)
        
        # 添加一个按钮来执行命令
        execute_button = tk.Button(self, text="Execute", command=self.parseAndExecute)
        execute_button.pack(side=tk.TOP, pady=5)
        
        # 中间：画布
        self.canvas.pack(side=tk.TOP, fill=tk.BOTH, expand=True, padx=5, pady=5)
        
        # 底部：状态栏（可选）
        self.status_label = tk.Label(self, text="Ready", bd=1, relief=tk.SUNKEN, anchor=tk.W)
        self.status_label.pack(side=tk.BOTTOM, fill=tk.X)
    
    def bind_events(self):
        """绑定事件处理器"""
        # 绑定回车键到文本框
        self.programTextField.bind('<Return>', self.actionPerformed)
        
        # 绑定窗口关闭事件
        self.master.protocol("WM_DELETE_WINDOW", self.on_window_closing)
    
    def actionPerformed(self, event=None):
        """动作事件处理器，对应Java的actionPerformed"""
        if event and event.widget == self.programTextField:
            self.parseAndExecute()
    
    def parseAndExecute(self):
        """解析并执行命令"""
        program_text = self.programTextField.get()
        print(f"programText = {program_text}")
        
        try:
            # 解析命令
            success = self.facade.parse(program_text)
            
            if success:
                # 重新绘制画布
                self.canvas.paint()
                self.status_label.config(text="Execution successful", fg="green")
            else:
                self.status_label.config(text="Parse failed", fg="red")
                
        except Exception as e:
            print(f"Error: {e}")
            self.status_label.config(text=f"Error: {str(e)}", fg="red")
    
    def on_window_closing(self):
        """窗口关闭事件处理器"""
        print("Closing window...")
        self.master.destroy()
        sys.exit(0)

if __name__ == "__main__":
    root = tk.Tk()
    main_app = Main(root)
    main_app.pack(fill=tk.BOTH, expand=True)
    
    root.mainloop()
