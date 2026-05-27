
from tkinter import Canvas
from language import Executor
from language import ExecutorFactory
from language import ExecuteException

class TurtleCanvas(Canvas, ExecutorFactory):
    UNIT_LENGTH = 30  # 前进时的长度单位
    DIRECTION_UP = 0  # 上方
    DIRECTION_RIGHT = 3  # 右方
    DIRECTION_DOWN = 6  # 下方
    DIRECTION_LEFT = 9  # 左方
    RELATIVE_DIRECTION_RIGHT = 3  # 右转
    RELATIVE_DIRECTION_LEFT = -3  # 左转
    RADIUS = 3  # 半径
    
    def __init__(self, master, width, height):
        super().__init__(master, width=width, height=height, bg='white')
        self.direction = 0
        self.position = None
        self.executor = None
        self.master = master
        self.width = width
        self.height = height
        self.initialize()
    
    def set_executor(self, executor):
        self.executor = executor
    
    def set_relative_direction(self, relative_direction):
        self.set_direction(self.direction + relative_direction)
    
    def set_direction(self, direction):
        if direction < 0:
            direction = 12 - (-direction) % 12
        else:
            direction = direction % 12
        self.direction = direction % 12
    
    def go(self, length):
        newx = self.position[0]
        newy = self.position[1]
        
        if self.direction == self.DIRECTION_UP:
            newy -= length
        elif self.direction == self.DIRECTION_RIGHT:
            newx += length
        elif self.direction == self.DIRECTION_DOWN:
            newy += length
        elif self.direction == self.DIRECTION_LEFT:
            newx -= length
        
        # 绘制线条
        self.create_line(self.position[0], self.position[1], newx, newy, fill='red')
        # 绘制圆点
        self.create_oval(newx - self.RADIUS, newy - self.RADIUS, 
                        newx + self.RADIUS, newy + self.RADIUS, 
                        fill='red', outline='red')
        
        self.position = (newx, newy)
    
    def createExecutor(self, name):
        if name == "go":
            return GoExecutor(self)
        elif name == "right":
            return DirectionExecutor(self, self.RELATIVE_DIRECTION_RIGHT)
        elif name == "left":
            return DirectionExecutor(self, self.RELATIVE_DIRECTION_LEFT)
        else:
            return None
    
    def initialize(self):
        self.position = (self.width // 2, self.height // 2)
        self.direction = 0
        self.delete("all")  # 清除画布
        self.configure(bg='white')
    
    def paint(self):
        """重新绘制画布"""
        self.initialize()
        if self.executor is not None:
            try:
                self.executor.execute()
            except ExecuteException:
                pass

class TurtleExecutor(Executor):
    def __init__(self, canvas):
        self.canvas = canvas

class GoExecutor(TurtleExecutor):
    def __init__(self, canvas):
        super().__init__(canvas)
    
    def execute(self):
        self.canvas.go(TurtleCanvas.UNIT_LENGTH)

class DirectionExecutor(TurtleExecutor):
    def __init__(self, canvas, relative_direction):
        super().__init__(canvas)
        self.relative_direction = relative_direction
    
    def execute(self):
        self.canvas.set_relative_direction(self.relative_direction)

