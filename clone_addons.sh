#!/bin/bash

# Dependencies for ofxTimeline

cd ../

if [ -z $1 ]; then
    PREFIX="git clone https://github.com/"
else
    PREFIX="git clone git@github.com:"
fi

${PREFIX}emmanuelgeoffray/ofxAvahiClient.git
${PREFIX}soixantecircuits/ofxSocketIO.git -b develop

