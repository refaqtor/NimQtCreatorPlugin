#pragma once

#include <projectexplorer/buildstep.h>

namespace Ui {
    class NimCompilerBuildStepConfigWidget;
}

namespace NimPlugin {

class NimCompilerBuildStep;

class NimCompilerBuildStepConfigWidget : public ProjectExplorer::BuildStepConfigWidget
{
    Q_OBJECT
public:
    /// Constructor
    NimCompilerBuildStepConfigWidget(NimCompilerBuildStep* buildStep);

    /// Destructor
    virtual ~NimCompilerBuildStepConfigWidget();

    QString summaryText() const Q_DECL_OVERRIDE;
    QString displayName() const Q_DECL_OVERRIDE;

private Q_SLOTS:
    void updateUI();

    void onAdditionalArgumentsTextEdited(const QString& text);
    void onTargetChanged(int index);

private:
    void connectBuildConfigurationSignals();
    void connectUISignals();

    void updateBuildDirectory();
    void updateCommandLineText();
    void updateTargetComboBox();
    void updateAdditionalArgumentsLineEdit();

    NimCompilerBuildStep* m_buildStep;
    Ui::NimCompilerBuildStepConfigWidget* m_ui;
};

}
