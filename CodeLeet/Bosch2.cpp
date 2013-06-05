/*Question 2: Voice recognition and playback

Suppose we have a system which can record user's speech, translate it into text (Speech Recognition),
and play the text back (Text-to-Speech).

The following is the class for speech recording and recognition. This class is ready for you to use.
	class SpeechRecognizer{
		//call this method to record user's speech and perform the speech recognition
		//this is an asynchronous method which returns immediately
		void startRecordAndRecognize();
	}
The result of speech recognition (i.e., the text) is returned by the following callback method
which is already registered in the SpeechRecognizer class.
	void recognitionResult(String text);

The following is the class for text to be played back. This class is ready for you to use.
	class TextAudioPlayer{
		//call this method to convert the text to audio, and then play back the audio
		//this is an asynchronous method which returns immediately
		void startTextPlayback(String text);
	}
When the playback is done, the following callback method is invoked by the TextAudioPlayer.
This method is already registered in the TextAudioPlayer class.
	void playbackDone();

The system has a button on the interface. 
Once the user clicks this button, the system should perform the speech recognition and play back the recognition result.

Please realize the following three methods.
Keep in mind that at any point in time, the system can only do one recording and speech recognition due to device conflict.
Also the system cannot do speech recognition and text play back at the same time due to device conflict.

Feel free add any variables you need to use.
You can add any methods to the SpeechRecognizer and TextAudioPlayer classes if you need these methods and 
believe they should be provided by these classes.


//SpeechRecognizer and TextAudioPlayer instances ready for you to use
SpeechRecognizer spRecongizer;
TextAudioPlayer auPlayer;


//called when the user clicked the button on the interface
void buttonClicked(){


}

//callback method for SpeechRecognizer
void recognitionResult(String text)
{


}

//callback method for TextAudioPlayer
void playbackDone()
{


}


Author: Wencan Luo
Language: C++
Date: 02/12/2013
*/

class SpeechRecognizer{
	//call this method to record user's speech and perform the speech recognition
	//this is an asynchronous method which returns immediately
	void startRecordAndRecognize();
		
	//flag to indicate the busy state of the recognizer and the player
	bool busy;
};

class TextAudioPlayer{
	//call this method to convert the text to audio, and then play back the audio
	//this is an asynchronous method which returns immediately
	void startTextPlayback(String text);

	bool busy;
};

SpeechRecognizer spRecongizer;
TextAudioPlayer auPlayer;

bool initialed = false;

void Initial()
{
	spRecongizer.busy = false;
	auPlayer.busy = false;

	initialed = true;
}

//called when the user clicked the button on the interface
void buttonClicked(){
	if( !initialed)//first time to run the system
	{
		Initial();
	}

	//Check whether the last recognizer and player finished, if not, do nothing
	if(spRecongizer.busy || auPlayer.busy) 
		return;

	//start recognizer
	spRecongizer.busy = true; //mark the state of the recongizer
	spRecongizer.startRecordAndRecognize();
}

//callback method for SpeechRecognizer
void recognitionResult(String text)
{
	//end the recognizer
	spRecongizer.busy = false;

	//start the player
	auPlayer.busy = true;
	auPlayer.startTextPlayback(text);
}

//callback method for TextAudioPlayer
void playbackDone()
{
	auPlayer.busy = false;
}
