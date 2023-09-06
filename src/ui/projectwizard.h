#ifndef PROJECTWIZARD_H
#define PROJECTWIZARD_H

#include <QWidget>

namespace Ui {
class ProjectWizard;
}

class ProjectWizard : public QWidget
{
    Q_OBJECT

public:
    explicit ProjectWizard(QWidget *parent = nullptr);
    ~ProjectWizard();

signals:
    void handleWindowChange(std::string name, int height, int width);

private:
    Ui::ProjectWizard *ui;

    std::string m_name;
    int m_width, m_height;
};

#endif // PROJECTWIZARD_H
