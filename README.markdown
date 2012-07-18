<h1>A basic test</h1>

This is my basic Haskell-to-C-to-OGRE test.

Right now, it's just C-to-C-to-OGRE.  Rather, fakehaskell.cpp communicates with external.cpp.  All that's exposed right now is the ability to influence scene creation.

(Instead of the lifecycle of the app starting in main() and ending up in the DemoApp which controls everything, main() instead goes straight to fakeHaskell(), which calls an init function on DemoApp (which then returns), and then calls a bunch of scene setup functions (that are the equivalent of what used to be in DemoApp::setupDemoScene()), and then passes control back to DemoApp good and proper (DemoApp::runDemo())).

It is a start.  I'm not going to keep DemoApp & the OGRE tutorial framework around past the proper completion of this test.

I am probably too pleased that even what I have so far, actually replicates the function of the original demo.

This is a modified OGRE sample app.

For more info of wot eye did, please see [my ramblings on the appropriate Google doc](https://docs.google.com/document/d/1Vg27KyF8dt1ozbSYOAJ6LzdBWD8ou1vmGP4nW_lPGWM/edit).
