# Contributing to Weather Station Project

Thank you for your interest in contributing to the Weather Station project! We appreciate your involvement and look forward to collaborating with you. Please follow these guidelines to ensure a smooth contribution process.

## Code of Conduct

By participating in this project, you agree to abide by our [Code of Conduct](CODE_OF_CONDUCT.md). Please read it before engaging in any interactions with other contributors.

## Reporting Issues

If you encounter any problems or have suggestions for new features, please open an issue in the project's issue tracker on GitHub. Be sure to provide enough information for us to understand and reproduce the problem.

## Branching Model

We follow a Git-Flow-inspired branching model to ensure well-organized development:

1. `main` branch: This branch contains the stable version of the code ready for production. Each release is tagged in this branch.

2. `develop` branch: This branch serves as the basis for active development and integration of new features. All new developments should take place in feature branches and be merged back into the `develop` branch.

3. Feature branches: These branches are created for the development of new features or improvements. They are created from the `develop` branch and merged back into it once development is complete.

   Example: `feature/temperature-sensor`

4. Release branches: When the `develop` branch has reached sufficient stability and a new version is to be released, a release branch is created. Final changes and bug fixes are made in this branch before merging the release into the `main` branch.

   Example: `release/v1.0.0`

5. Hotfix branches: These branches are created when urgent bug fixes are required in the production version. They are created from the `main` branch and merged back into both the `main` and `develop` branches once the bug fix is complete.

   Example: `hotfix/1.0.1`

Please follow this branching model when contributing to the project.

## Submitting Pull Requests

When you're ready to submit your changes, please create a pull request against the appropriate branch (usually `develop`). Be sure to describe your changes in detail and reference any related issues.

Your pull request will be reviewed by the maintainers, who may request changes or provide feedback. Once your changes have been approved, they will be merged into the appropriate branch.

Thank you for your contributions!

---

# Beitrag zum Weather Station Projekt

Vielen Dank für Ihr Interesse an der Mitarbeit am Weather Station Projekt! Wir schätzen Ihr Engagement und freuen uns auf die Zusammenarbeit mit Ihnen. Bitte beachten Sie diese Richtlinien, um einen reibungslosen Beitragungsprozess zu gewährleisten.

## Verhaltenskodex

Durch die Teilnahme an diesem Projekt erklären Sie sich damit einverstanden, unseren [Verhaltenskodex](CODE_OF_CONDUCT.md) einzuhalten. Bitte lesen Sie diesen, bevor Sie sich in Interaktionen mit anderen Mitwirkenden einlassen.

## Probleme melden

Wenn Sie auf Probleme stoßen oder Vorschläge für neue Funktionen haben, öffnen Sie bitte ein Issue im Issue-Tracker des Projekts auf GitHub. Stellen Sie sicher, dass Sie genügend Informationen bereitstellen, damit wir das Problem verstehen und reproduzieren können.

## Branching-Modell

Wir folgen einem vom Git-Flow inspirierten Branching-Modell, um eine gut organisierte Entwicklung zu gewährleisten:

1. `main`-Branch: Dieser Branch enthält die stabile Version des Codes, die für die Produktion bereit ist. Jedes Release wird in diesem Branch getaggt.

2. `develop`-Branch: Dieser Branch dient als Grundlage für die aktive Entwicklung und Integration neuer Funktionen. Alle neuen Entwicklungen sollten in Feature-Branches stattfinden und in den `develop`-Branch zurückgemergt werden.

3. Feature-Branches: Diese Branches werden für die Entwicklung neuer Funktionen oder Verbesserungen erstellt. Sie werden vom `develop`-Branch erstellt und nach Abschluss der Entwicklung wieder in diesen zurückgemergt.

   Beispiel: `feature/temperature-sensor`

4. Release-Branches: Wenn der `develop`-Branch eine ausreichende Stabilität erreicht hat und eine neue Version veröffentlicht werden soll, wird ein Release-Branch erstellt. In diesem Branch werden die letzten Änderungen und Fehlerbehebungen vorgenommen, bevor das Release in den `main`-Branch gemergt wird.

   Beispiel: `release/v1.0.0`

5. Hotfix-Branches: Diese Branches werden erstellt, wenn dringende Fehlerbehebungen in der Produktionsversion erforderlich sind. Sie werden vom `main`-Branch erstellt und nach Abschluss der Fehlerbehebung in den `main`- und `develop`-Branch zurückgemergt.

   Beispiel: `hotfix/1.0.1`

Bitte folgen Sie diesem Branching-Modell, wenn Sie zum Projekt beitragen.

## Pull Requests einreichen

Wenn Sie Ihre Änderungen einreichen möchten, erstellen Sie bitte einen Pull Request gegen den entsprechenden Branch (normalerweise `develop`). Beschreiben Sie Ihre Änderungen ausführlich und verweisen Sie auf alle zugehörigen Issues.

Ihr Pull Request wird von den Maintainers überprüft, die möglicherweise Änderungen anfordern oder Rückmeldungen geben. Sobald Ihre Änderungen genehmigt wurden, werden sie in den entsprechenden Branch gemergt.

Vielen Dank für Ihre Beiträge!
