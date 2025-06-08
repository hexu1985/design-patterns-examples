
from ProgramNode import ProgramNode
from Context import Context

def main():
    file_path = "program.txt"

    with open(file_path) as ifile:
        for text in ifile:
            text = text.rstrip()
            print('text = "{}"'.format(text))
            node = ProgramNode()
            context = Context(text)
            node.parse(context)
            print("node = {}".format(node))

if __name__ == "__main__":
    main()
