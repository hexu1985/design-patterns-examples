#include <QApplication>
#include <QMainWindow>
#include <QListWidget>
#include <QTreeWidget>
#include <QFrame>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QHeaderView>
#include <QGroupBox>

// 前向声明
class VisList;

// Bridger类 - 对应Python的Bridger
class Bridger : public QObject {
    Q_OBJECT
public:
    Bridger(QWidget* parent = nullptr) : QObject(parent) {}
    virtual ~Bridger() = default;
    virtual void addData(const QList<class Product*>& products) = 0;
};

// VisList接口 - 对应Python的VisList
class VisList {
public:
    virtual ~VisList() = default;
    virtual void addLines(const QList<class Product*>& prodlist) = 0;
    virtual void removeLine() {}
};

// Product类 - 对应Python的Product
class Product {
public:
    Product(const QString& nstring) {
        // 分割字符串
        QStringList strings = nstring.split("--");
        if (strings.size() >= 2) {
            name = strings[0].trimmed();
            count = strings[1].trimmed();
        }
    }
    
    QString name;
    QString count;
};

// Products类 - 对应Python的Products
class Products {
public:
    void read(const QString& fname) {
        QFile file(fname);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            _products.clear();
            
            while (!in.atEnd()) {
                QString line = in.readLine();
                if (!line.trimmed().isEmpty()) {
                    _products.append(new Product(line));
                }
            }
            file.close();
        }
    }
    
    QList<Product*> getProducts() const {
        return _products;
    }
    
    ~Products() {
        qDeleteAll(_products);
    }
    
private:
    QList<Product*> _products;
};

// Listbox visual list - 对应Python的LbVisList
class LbVisList : public QListWidget, public VisList {
    Q_OBJECT
public:
    LbVisList(QWidget* frame) : QListWidget(frame) {}
    
    void addLines(const QList<Product*>& prodlist) override {
        for (Product* prod : prodlist) {
            addItem(prod->name);
        }
    }
};

// Treelist (table) visual list - 对应Python的TbVisList
class TbVisList : public QTreeWidget, public VisList {
    Q_OBJECT
public:
    TbVisList(QWidget* frame) : QTreeWidget(frame) {
        // 设置列
        setColumnCount(2);
        QStringList headers;
        headers << "Part" << "Qty";
        setHeaderLabels(headers);
        
        // 设置列宽
        header()->setSectionResizeMode(0, QHeaderView::Fixed);
        header()->setSectionResizeMode(1, QHeaderView::Fixed);
        setColumnWidth(0, 150);
        setColumnWidth(1, 50);
        
        index = 0;
    }
    
    void addLines(const QList<Product*>& prodlist) override {
        for (Product* prod : prodlist) {
            QTreeWidgetItem* item = new QTreeWidgetItem(this);
            item->setText(0, prod->name);
            item->setText(1, prod->count);
            index++;
        }
    }
    
private:
    int index;
};

// General bridge between data and any VisList class
// 对应Python的ListBridge
class ListBridge : public Bridger {
public:
    ListBridge(QWidget* frame, VisList* vislist) : Bridger(frame) {
        list = vislist;
        // 将widget添加到frame的布局中
        if (auto* widget = dynamic_cast<QWidget*>(vislist)) {
            if (auto* layout = frame->layout()) {
                layout->addWidget(widget);
            }
        }
    }
    
    void addData(const QList<Product*>& products) override {
        list->addLines(products);
    }
    
private:
    VisList* list;
};

// creates the user interface - 对应Python的BuildUI
class BuildUI : public QMainWindow {
    Q_OBJECT
public:
    BuildUI(QWidget* parent = nullptr) : QMainWindow(parent) {}
    
    void build() {
        // 设置窗口属性
        setWindowTitle("Parts list");
        resize(335, 200);
        
        // 创建中央widget
        QWidget* centralWidget = new QWidget(this);
        setCentralWidget(centralWidget);
        
        // 创建主布局
        QHBoxLayout* mainLayout = new QHBoxLayout(centralWidget);
        
        // 读取产品数据
        Products prod;
        prod.read("products.txt");
        
        // 创建左侧frame
        QFrame* lframe = new QFrame(centralWidget);
        lframe->setFrameStyle(QFrame::Box | QFrame::Raised);
        lframe->setMinimumWidth(200);
        QVBoxLayout* lframeLayout = new QVBoxLayout(lframe);
        
        QLabel* leftlabel = new QLabel("Customer view", lframe);
        lframeLayout->addWidget(leftlabel);
        
        // 创建左侧列表
        LbVisList* vislist = new LbVisList(lframe);
        lframeLayout->addWidget(vislist);
        
        ListBridge* lbridge = new ListBridge(lframe, vislist);
        lbridge->addData(prod.getProducts());
        
        mainLayout->addWidget(lframe);
        
        // 创建右侧frame
        QFrame* rframe = new QFrame(centralWidget);
        rframe->setFrameStyle(QFrame::Box | QFrame::Raised);
        QVBoxLayout* rframeLayout = new QVBoxLayout(rframe);
        
        QLabel* rlabel = new QLabel("Executive view", rframe);
        rframeLayout->addWidget(rlabel);
        
        // 创建右侧表格
        TbVisList* rvislist = new TbVisList(rframe);
        rframeLayout->addWidget(rvislist);
        
        ListBridge* rlb = new ListBridge(rframe, rvislist);
        rlb->addData(prod.getProducts());
        
        mainLayout->addWidget(rframe);
    }
};

// 对应Python的main函数
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    
    BuildUI* ui = new BuildUI();
    ui->build();
    ui->show();
    
    return app.exec();
}

#include "BasicBridge.moc"
