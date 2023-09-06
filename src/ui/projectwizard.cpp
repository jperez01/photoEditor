#include "projectwizard.h"
#include "ui_projectwizard.h"

#include <iostream>

ProjectWizard::ProjectWizard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProjectWizard)
{
    ui->setupUi(this);
    ui->titleLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);

    ui->heightBox->setRange(100, 3000);
    ui->heightBox->setValue(500);
    ui->widthBox->setRange(100, 3000);
    ui->widthBox->setValue(500);
    m_height = 500;
    m_width = 500;
    connect(ui->nameEdit, &QLineEdit::textChanged, [&] {
        QString name = ui->nameEdit->text();
        m_name = name.toStdString();
    });

    connect(ui->heightBox, &QSpinBox::valueChanged, [&] {
        m_height = ui->heightBox->value();
    });
    connect(ui->widthBox, &QSpinBox::valueChanged, [&] {
        m_width = ui->widthBox->value();
    });

    connect(ui->createButton, &QPushButton::clicked, [&] {
        if (m_height > 10 && m_width > 10 && !m_name.empty())
            handleWindowChange(m_name, m_height, m_width);
        else
            std::cout << "Invalid Parameters \n";
    });
}

ProjectWizard::~ProjectWizard()
{
    delete ui;
}
