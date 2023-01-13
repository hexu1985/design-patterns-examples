
from Element import Element

class ElementArrayList(list, Element):
    def accept(self, v):
        for e in self:
            e.accept(v)
