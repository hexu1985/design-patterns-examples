from tkinter import *

class ScrolledText(Frame):
    def __init__(self, parent=None, text='', height=20, width=40):
        Frame.__init__(self, parent)
        self.makeWidgets(height, width)
        self.setText(text)

    def makeWidgets(self, height, width):
        sbar = Scrollbar(self)
        text = Text(self, relief=SUNKEN, height=height, width=width)
        sbar.config(command=text.yview)                  # xlink sbar and text
        text.config(yscrollcommand=sbar.set)             # move one moves other
        sbar.pack(side=RIGHT, fill=Y)                    # pack first=clip last
        text.pack(side=LEFT, expand=YES, fill=BOTH)      # text clipped first
        self.text = text

    def setText(self, text=''):
        self.text.delete('1.0', END)                     # delete current text
        self.text.insert('1.0', text)                    # add at line 1, col 0
        self.text.mark_set(INSERT, '1.0')                # set insert cursor
        self.text.focus()                                # save user a click

    def getText(self):                                   # returns a string
        return self.text.get('1.0', END+'-1c')           # first through last

    def appendText(self, text):
        self.text.insert(END, text)
        self.text.mark_set(INSERT, '1.0')                # set insert cursor
        self.text.focus()                                # save user a click

if __name__ == '__main__':
    root = Tk()
    st = ScrolledText(root, text='Words\ngo here')         # or not: two lines
    st.pack()
    for i in range(3):
        st.appendText(text=str(i)+": hello world\n")
    def show(event): 
        print(repr(st.gettext()))                        # show as raw string
    root.bind('<Key-Escape>', show)                      # esc = dump text
    root.mainloop()
