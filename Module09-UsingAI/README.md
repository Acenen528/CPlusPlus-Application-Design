Concept of AI implimentation in an application.

Concept: An application that takes a electrical signals from the brain and classifies
            whether the person is thinking of raising their left or right hand.

C++ Application
    1. Recieve real-time electric brain signals from a headset that the user is using.
    2. Application recieves the data and processes the signals
    3. The application sends the processed data over to an AI model.
    4. The AI model which is trained to predict left vs right hand brain signals
        receives the data and outputs a result (left or right).
    5. The application recieves the result and outputs it.

Possible usages:
    By using AI to classify motor signals from the brain, disabled individuals that may have lost a limb
    can control a robotic limb jsut by thinking. If they want to raise their a robotic hand, they can imagine
    doing so, and taking their brain signals, we feed it to the robotic arms and it'll know which hand to raise.

Implementation:
    A version using a machine learning approach called CSP (Common Spatial Patterns) and LDA (Linear Discriminative Analysis) is used here on my github.
    https://github.com/Acenen528/eeg-motor-imagery-csp-lda

    The program requires using training data from a subject to fit the parameters of the CSP+LDA model before being able to classify data.
    In other words, the model needs to be trained by the user first before being able to predict left vs. right hand brain signals.

    The reason is because brain signals vary heavily between people, therefore a universally-trained brain classification model does not exist. This training step serves as a calibration step to make sure the model an understand a person's unique brain signals.

    More details are provided in the readme of that repository of any that'd like to test the code