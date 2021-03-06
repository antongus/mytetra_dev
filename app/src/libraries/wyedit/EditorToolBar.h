#ifndef EDITORTOOLBAR_H
#define EDITORTOOLBAR_H

#include <QWidget>
#include <QToolButton>
#include <QFontComboBox>
#include <QSpinBox>
#include <QToolBar>
#include <QVBoxLayout>

#include "EditorFontSizeComboBox.h"
#include "EditorFontFamilyComboBox.h"


// Виджет для отрисовки кнопок форматирования текста
// Является базовым для EditorToolBarAssistant

class EditorToolBar : public QWidget
{
  Q_OBJECT

public:

  explicit EditorToolBar(QWidget *parent = nullptr);
  virtual ~EditorToolBar();

  // Область, содержащая линейки с кнопками форматирования
  QVBoxLayout textformatButtonsLayout;

  // Линейки с кнопками форматирования текста
  QToolBar    toolsLine1;
  QToolBar    toolsLine2;

  // Кнопки форматирования текста
  QAction *bold;
  QAction *italic;
  QAction *underline;
  QAction *monospace;
  QAction *code;
  QAction *clear; // Очистка начертания текста
  QAction *textOnly; // Полная очистка текста (оставить один текст)
  QAction *fixBreakSymbol;

  QAction *numericList;
  QAction *dotList;

  QAction *indentPlus;
  QAction *indentMinus;

  QAction *alignLeft;
  QAction *alignCenter;
  QAction *alignRight;
  QAction *alignWidth;

  QAction *settings;

  EditorFontFamilyComboBox *fontSelect;
  EditorFontSizeComboBox   *fontSize;
  QAction                  *fontColor;

  QAction *reference;

  QAction *showHtml;

  QAction *findText;

  QAction *showFormatting;

  QAction *createTable;
  QAction *tableRemoveRow;
  QAction *tableRemoveCol;
  QAction *tableAddRow;
  QAction *tableAddCol;
  QAction *tableMergeCells;
  QAction *tableSplitCell;
  QAction *tableProperties;

  QAction *insertImageFromFile;
  QAction *mathExpression;
  QAction *expandEditArea;
  QAction *expandToolsLines;
  QAction *save;

  QAction *back;
  QAction *findInBase;

  QAction *showText;

  QAction *toAttach;

  QIcon         iconAttachExists; // Иконка, когда аттачи есть
  QIcon         iconAttachNotExists; // Иконка, когда аттачей нет

  void init();

  void initDisableToolList(QStringList toolNames); // Список кнопок, которые нельзя использовать - они будут невидны (не добавлены)
  void setEnableModifyTextButton(bool state); // Установка или снятие доступности кнопок, модифицирующих текст

  void initToolsLine1(QStringList toolsLine);
  void initToolsLine2(QStringList toolsLine);

  void switchAttachIconExists(bool isExists); // Переключение иконки аттачей в режим есть аттачи или нет аттачей

signals:

public slots:


protected:

  bool isInit;

  QStringList toolsListInLine1;
  QStringList toolsListInLine2;

  // Список инструментов, которые не нужно подгружать
  QStringList disableToolList;

  QVector<QAction *> actions; // Делать массив объектов вместо указателей на объект нельзя, невозможно работать с QAction в контейнере QVector

  void setupToolBarTools(void);
  void setupShortcuts(void);
  void assemblyButtons(void);

  void insertButtonToToolsLine(QString toolName, QToolBar &line);

  QList<QWidget *> getButtonWidgetList(void);
  void hideAllToolsElements(void);

  void updateToolsLines(void);

  QAction* generateAction(QIcon icon=QIcon());

};

#endif // EDITORTOOLBAR_H
