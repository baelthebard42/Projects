# Training model for detecting traffic signals

## Attempt 1 

Convolution : 32 and (2, 2), Pooling : (2, 2), Dense: 128, Dropout: 0.5

This gave a very very low accuracy of 6%. Might be the density of the networks wasn't enough.



## Attempt 2

Convolution : 60 and (2, 2),  Pooling : (2, 2), Dense: 128, Dropout: 0.5

No significant change was noticed. 


## Attempt 3

Convolution : 60 and (2, 2), Pooling : (2, 2), Dense: 256, Dropout: 0.5

The accuracy sky rocketed to 88%. So, higher density resulted in higher accuracy.


## Attempt 4

Convolution : 60 and (4, 4), Pooling : (2, 2), Dense: 256, Dropout: 0.5

Initially there was a really high rate of increase. First epoch gave accuracy of 27% then it upped to 68% in second. The final accuracy was about 93%. So, increasing size of kernel matrix increased accuracy.



## Attempt 5

Convolution : 60 and (6, 6), Pooling : (2, 2), Dense: 256, Dropout: 0.5

Here too initially it was really high. The final accuracy was 93%. But in between the epochs, the accuracies were better than attempt 4.


## Attempt 6

I put the Pooling to (1, 1). It took so so long to train that I interrupted by pressing ctrl+c. The accuracy was 85% on 6th epoch. It probably took so much time because the input size is basically same as the original input. So, it took a long to process the huge amount of data.



## Attempt 7

Convolution : 60 and (6, 6), Pooling : (2, 2), Dense: 256, Dropout: 0.8

The accuracy declined by a lot. It went all the way to 48%. This was probably because I dropped too many neurons than required and hence, information and patterns got lost.


## Attempt 8

Convolution : 60 and (6, 6), Pooling : (2, 2), Dense: 512, Dropout: 0.5


Accuracy was of 91% here. It declined because too much density of neurons probably caused overfitting. 


## Attempt 9

Convolution : 60 and (6, 6), Pooling : (3, 3), Dense: 256, Dropout: 0.5

This resulted in accuracy of 89% but the training completed very quickly as pooling increased and increased pooling leads to less input.







