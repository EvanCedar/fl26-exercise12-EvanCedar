#include <QtTest/QtTest>
#include <QtWidgets>
#include <QDebug>

#include "toggle_widget.h"

class TestToggleWidget : public QObject {
  Q_OBJECT

private slots:

  // Define tests here
  void initiallyOff();
  void clickTogglesOnThenOff();
  void repeatedClicksAlternate();
};

// Implement the tests here

void TestToggleWidget::initiallyOff()
{
  ToggleWidget w;
  QCOMPARE(w.isOn(), false);
}

void TestToggleWidget::clickTogglesOnThenOff()
{
  ToggleWidget w;
  w.show();
  QVERIFY(QTest::qWaitForWindowExposed(&w));

  QPushButton *pb = w.findChild<QPushButton *>();
  QVERIFY2(pb != nullptr, "ToggleWidget should contain a QPushButton");

  QCOMPARE(w.isOn(), false);

  QTest::mouseClick(pb, Qt::LeftButton);
  QCOMPARE(w.isOn(), true);

  QTest::mouseClick(pb, Qt::LeftButton);
  QCOMPARE(w.isOn(), false);
}

void TestToggleWidget::repeatedClicksAlternate()
{
  ToggleWidget w;
  w.show();
  QVERIFY(QTest::qWaitForWindowExposed(&w));

  QPushButton *pb = w.findChild<QPushButton *>();
  QVERIFY2(pb != nullptr, "ToggleWidget should contain a QPushButton");

  for (int i = 1; i <= 6; ++i) {
    QTest::mouseClick(pb, Qt::LeftButton);
    QCOMPARE(w.isOn(), i % 2 == 1);   // odd clicks -> on, even clicks -> off
  }
}

QTEST_MAIN(TestToggleWidget)
#include "test_toggle_widget.moc"