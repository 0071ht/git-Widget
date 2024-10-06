#include <QApplication>
#include <QTabWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>
#include <QSpacerItem>
#include <QPushButton>
#include <QColorDialog>
#include <QPalette>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget *window = new QWidget;
    window->setWindowTitle("example");

    // 創建 QTabWidget
    QTabWidget *tabWidget = new QTabWidget;

    // 創建第一個標籤頁
    QWidget *tab1 = new QWidget;
    QVBoxLayout *layout1 = new QVBoxLayout;

    // 在垂直佈局中添加垂直空間和標籤
    QSpacerItem *topSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    layout1->addItem(topSpacer); // 上方的空間

    QLabel *label1 = new QLabel("隊長");
    QLabel *label2 = new QLabel("組員1");
    QLabel *label3 = new QLabel("組員2");
    QLabel *label4 = new QLabel("組員3");

    // 設置文字顏色為藍色
    label1->setStyleSheet("color: blue;");
    label2->setStyleSheet("color: blue;");
    label3->setStyleSheet("color: blue;");
    label4->setStyleSheet("color: blue;");

    // 將所有 QLabel 添加到佈局中
    layout1->addWidget(label1);
    layout1->addWidget(label2);
    layout1->addWidget(label3);
    layout1->addWidget(label4);

    QSpacerItem *bottomSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    layout1->addItem(bottomSpacer); // 下方的空間

    tab1->setLayout(layout1);
    tabWidget->addTab(tab1, "隊長");

    // 創建第二個標籤頁
    QWidget *tab2 = new QWidget;
    QVBoxLayout *layout2 = new QVBoxLayout;

    // 創建按鈕
    QPushButton *button = new QPushButton("color select");

    // 按鈕點擊事件
    QObject::connect(button, &QPushButton::clicked, [=]() {
        // 打開顏色選擇器
        QColor color = QColorDialog::getColor(Qt::blue, window, "color select");

        // 如果用戶選擇了有效顏色，改變隊長標籤的字體顏色
        if (color.isValid()) {
            QString colorName = color.name();  // 獲取選擇的顏色名稱
            label1->setStyleSheet(QString("color: %1;").arg(colorName));
            label2->setStyleSheet(QString("color: %1;").arg(colorName));
            label3->setStyleSheet(QString("color: %1;").arg(colorName));
            label4->setStyleSheet(QString("color: %1;").arg(colorName));
        }
    });

    // 將按鈕添加到佈局中
    layout2->addWidget(button);
    tab2->setLayout(layout2);
    tabWidget->addTab(tab2, "組員1");

    // 創建第三個標籤頁，不放內容
    QWidget *tab3 = new QWidget;
    tabWidget->addTab(tab3, "組員2");

    // 創建第四個標籤頁，不放內容
    QWidget *tab4 = new QWidget;
    tabWidget->addTab(tab4, "組員3");

    // 設置主窗口的佈局
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(tabWidget);
    window->setLayout(mainLayout);

    window->resize(400, 300); // 設置窗口大小
    window->show();

    return app.exec();
}
