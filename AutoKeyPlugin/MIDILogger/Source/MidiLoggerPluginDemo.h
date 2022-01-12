/*
  ==============================================================================

   This file is part of the JUCE examples.
   Copyright (c) 2020 - Raw Material Software Limited

   The code included in this file is provided under the terms of the ISC license
   http://www.isc.org/downloads/software-support-policy/isc-license. Permission
   To use, copy, modify, and/or distribute this software for any purpose with or
   without fee is hereby granted provided that the above copyright notice and
   this permission notice appear in all copies.

   THE SOFTWARE IS PROVIDED "AS IS" WITHOUT ANY WARRANTY, AND ALL WARRANTIES,
   WHETHER EXPRESSED OR IMPLIED, INCLUDING MERCHANTABILITY AND FITNESS FOR
   PURPOSE, ARE DISCLAIMED.

  ==============================================================================
*/

/*******************************************************************************
 The block below describes the properties of this PIP. A PIP is a short snippet
 of code that can be read by the Projucer and used to generate a JUCE project.

 BEGIN_JUCE_PIP_METADATA

 name:                  MIDILogger
 version:               1.0.0
 vendor:                JUCE
 website:               http://juce.com
 description:           Logs incoming MIDI messages.

 dependencies:          juce_audio_basics, juce_audio_devices, juce_audio_formats,
                        juce_audio_plugin_client, juce_audio_processors,
                        juce_audio_utils, juce_core, juce_data_structures,
                        juce_events, juce_graphics, juce_gui_basics, juce_gui_extra
 exporters:             xcode_mac, vs2019, linux_make

 moduleFlags:           JUCE_STRICT_REFCOUNTEDPOINTER=1

 type:                  AudioProcessor
 mainClass:             MidiLoggerPluginDemoProcessor

 useLocalCopy:          1

 pluginCharacteristics: pluginWantsMidiIn, pluginProducesMidiOut

 END_JUCE_PIP_METADATA

*******************************************************************************/

#pragma once

#include <iterator>
#include <set>
#include <vector>
#include <algorithm>

#define MACRO_VARIABLE_TO_STRING(Variable) (void(Variable),#Variable)

class MidiKeyFinder {
public:
  MidiKeyFinder() {

   }

  void reset() {
    Notes_Input.clear();
  }

  void add_midi_message(const juce::MidiMessage& m) {
    String s;

    if (m.isNoteOn())
      s = juce::MidiMessage::getMidiNoteName(m.getNoteNumber(), true, false, 3);
    else
      s = "";
    if (s == "A") { Notes_Input.insert(A); }
    else if (s == "A#") { Notes_Input.insert(AS);}
    else if (s == "B")  { Notes_Input.insert(B);}
    else if (s == "C")  { Notes_Input.insert(C);}
    else if (s == "C#") { Notes_Input.insert(CS);}
    else if (s == "D")  { Notes_Input.insert(D);}
    else if (s == "D#") { Notes_Input.insert(DS);}
    else if (s == "E")  { Notes_Input.insert(E);}
    else if (s == "F")  { Notes_Input.insert(F);}
    else if (s == "F#") { Notes_Input.insert(FS);}
    else if (s == "G")  { Notes_Input.insert(G);}
    else if (s == "G#") { Notes_Input.insert(GS);}


  }

  String testfunction(const juce::MidiMessage& m) {
    return juce::MidiMessage::getMidiNoteName(m.getNoteNumber(), true, false, 3);
  }

  String get_keys() {
    String s = "Possible keys:\n";
    bool no_matches = true;
    for (int i = 0; i < scales.size(); i++) {

      if (std::includes(scales[i].begin(), scales[i].end(),
                        Notes_Input.begin(), Notes_Input.end()))
      {
        no_matches = false;
        // THESE MATCH THE ORDER OF THE VECTOR
        if (i == 0) { s += "A Minor\n"; }
        else if (i == 1) { s += "A# Minor\n"; }
        else if (i == 2) { s += "B Minor\n"; }
        else if (i == 3) { s += "C Minor\n"; }
        else if (i == 4) { s += "C# Minor\n"; }
        else if (i == 5) { s += "D Minor\n"; }
        else if (i == 6) { s += "D# Minor\n"; }
        else if (i == 7) { s += "E Minor\n"; }
        else if (i == 8) { s += "F Minor\n"; }
        else if (i == 9) { s += "F# Minor\n"; }
        else if (i == 10) { s += "G Minor\n"; }
        else if (i == 11) { s += "G# Minor\n"; }
        else if (i == 12) { s += "C Major\n"; }
        else if (i == 13) { s += "G Major\n"; }
        else if (i == 14) { s += "D Major\n"; }
        else if (i == 15) { s += "A Major\n"; }
        else if (i == 16) { s += "E Major\n"; }
        else if (i == 17) { s += "B Major\n"; }
        else if (i == 18) { s += "F Major\n"; }
        else if (i == 19) { s += "A# Major\n"; }
        else if (i == 20) { s += "D# Major\n"; }
        else if (i == 21) { s += "G# Major\n"; }
        else if (i == 22) { s += "C# Major\n"; }
        else if (i == 23) { s += "F# Major\n"; }
      }
    }
    if (no_matches) {
      s = "No matching keys\n";
    }
    return s;
  }


private:
  /*
  Db-C#
  Eb-D#
  Gb-F#
  Ab-G#
  Bb-A#*/
 
  enum Note {C, CS, D, DS, E, F, FS, G, GS, A, AS, B};

  std::set<Note> AMinor  = { A,B,C,D,E,F,G,A };
  std::set<Note> ASMinor = { AS,C,CS,DS,F,FS,GS };
  std::set<Note> BMinor  = { B,CS,D,E,FS,G,A,B };
  std::set<Note> CMinor  = { C,D,DS,F,G,GS,AS,C };
  std::set<Note> CSMinor = { CS,DS,E,FS,GS,A,B };
  std::set<Note> DMinor  = { D,E,F,G,A,AS,C };
  std::set<Note> DSMinor = { DS,F,FS,GS,AS,B,CS };
  std::set<Note> EMinor  = { E,FS,G,A,B,C,D };
  std::set<Note> FMinor  = { F,G,GS,AS,C,CS,DS };
  std::set<Note> FSMinor = { FS,GS,A,B,CS,D,E };
  std::set<Note> GMinor  = { G,A,AS,C,D,DS,F };
  std::set<Note> GSMinor = { GS,AS,B,CS,DS,E,FS };

  std::set<Note> CMajor = { C,D,E,F,G,A,B };
  std::set<Note> GMajor = { G,A,B,C,D,E,FS };
  std::set<Note> DMajor = { D,E,FS,G,A,B,CS };
  std::set<Note> AMajor = { A,B,CS,D,E,FS,GS };
  std::set<Note> EMajor = { E,FS,GS,A,B,CS,DS };
  std::set<Note> BMajor = { B,CS,DS,E,FS,GS,AS };
  std::set<Note> FMajor = { F,G,A,AS,C,D,E };
  std::set<Note> ASMajor = { AS,C,D,DS,F,G,A };
  std::set<Note> DSMajor = { DS,F,G,GS,AS,C,D };
  std::set<Note> GSMajor = { GS,AS,C,CS,DS,F,G };
  std::set<Note> CSMajor = { CS,DS,F,FS,GS,AS,C };
  std::set<Note> FSMajor = { FS,GS,AS,B,CS,DS,F };

  std::set<Note> Notes_Input = {};

  // DON'T CHANGE ORDER OF SCALES. THEY ARE HARD CODEDED IN FUNCTIONS ABOVE
  std::vector<std::set<Note>> scales{
  AMinor,ASMinor,BMinor,CMinor,CSMinor,DMinor,DSMinor,EMinor,FMinor,FSMinor,GMinor,GSMinor,
  CMajor,GMajor,DMajor,AMajor,EMajor,BMajor,FMajor,ASMajor,DSMajor,GSMajor,CSMajor,FSMajor};


};

class MidiQueue
{
public:
    void push (const MidiBuffer& buffer)
    {
        for (const auto metadata : buffer)
            fifo.write (1).forEach ([&] (int dest) { messages[(size_t) dest] = metadata.getMessage(); });
    }

    template <typename OutputIt>
    void pop (OutputIt out)
    {
        fifo.read (fifo.getNumReady()).forEach ([&] (int source) { *out++ = messages[(size_t) source]; });
    }

private:
    static constexpr auto queueSize = 1 << 14;
    AbstractFifo fifo { queueSize };
    std::vector<MidiMessage> messages = std::vector<MidiMessage> (queueSize);
};

// Stores the last N messages. Safe to access from the message thread only.
class MidiListModel
{
public:
    template <typename It>
    void addMessages (It begin, It end)
    {
        const auto numNewMessages = (int) std::distance (begin, end);
        const auto numToAdd = juce::jmin (numToStore, numNewMessages);
        const auto numToRemove = jmax (0, (int) messages.size() + numToAdd - numToStore);
        messages.erase (messages.begin(), std::next (messages.begin(), numToRemove));
        messages.insert (messages.end(), std::prev (end, numToAdd), end);

        if (onChange != nullptr)
            onChange();
    }

    void clear()
    {
        messages.clear();

        if (onChange != nullptr)
            onChange();
    }

    const MidiMessage& operator[] (size_t ind) const     { return messages[ind]; }

    size_t size() const                                  { return messages.size(); }

    std::function<void()> onChange;

private:
    static constexpr auto numToStore = 1000;
    std::vector<MidiMessage> messages;
};

//==============================================================================
class MidiTable  : public Component,
                   private TableListBoxModel
{
public:
    MidiKeyFinder* Midi_Key_Finder_Util_Table;
    MidiTable (MidiListModel& m, MidiKeyFinder& mm)
        : messages (m),
        Midi_Key_Finder_Util_Table(&mm)
    {
        addAndMakeVisible (table);

        table.setModel (this);
        table.setClickingTogglesRowSelection (false);
        table.setHeader ([&]
        {
            auto header = std::make_unique<TableHeaderComponent>();
            header->addColumn ("Message", messageColumn, 200, 30, -1, TableHeaderComponent::notSortable);
            header->addColumn ("Channel", channelColumn, 100, 30, -1, TableHeaderComponent::notSortable);
            header->addColumn ("Data",    dataColumn,    200, 30, -1, TableHeaderComponent::notSortable);
            return header;
        }());
        messages.onChange = [&] { table.updateContent(); };
    }

    ~MidiTable() override { messages.onChange = nullptr; }

    void resized() override { table.setBounds (getLocalBounds()); }

private:
    enum
    {
        messageColumn = 1,
        channelColumn,
        dataColumn
    };

    int getNumRows() override          { return (int) messages.size(); }

    void paintRowBackground (Graphics&, int, int, int, bool) override {}
    void paintCell (Graphics&, int, int, int, int, bool)     override {}

    Component* refreshComponentForCell (int rowNumber,
                                        int columnId,
                                        bool,
                                        Component* existingComponentToUpdate) override
    {
        delete existingComponentToUpdate;

        const auto index = (int) messages.size() - 1 - rowNumber;
        const auto message = messages[(size_t) index];

        //Midi_Key_Finder_Util_Table->add_midi_message(message);

        
        
        

        return new Label ({}, [&]
        {

            switch (columnId)
            {
                case messageColumn: return getEventString (message);
                case channelColumn: return String (message.getChannel());
                case dataColumn:    return getDataString(message);

                default:            break;
            }

            jassertfalse;
            return String();
        }());
    }

    static String getEventString (const MidiMessage& m)
    {
        if (m.isNoteOn())           return "Note on";
        if (m.isNoteOff())          return "Note off";
        if (m.isProgramChange())    return "Program change";
        if (m.isPitchWheel())       return "Pitch wheel";
        if (m.isAftertouch())       return "Aftertouch";
        if (m.isChannelPressure())  return "Channel pressure";
        if (m.isAllNotesOff())      return "All notes off";
        if (m.isAllSoundOff())      return "All sound off";
        if (m.isMetaEvent())        return "Meta event";

        if (m.isController())
        {
            const auto* name = MidiMessage::getControllerName (m.getControllerNumber());
            return "Controller " + (name == nullptr ? String (m.getControllerNumber()) : String (name));
        }

        return String::toHexString (m.getRawData(), m.getRawDataSize());
    }

    static String getDataString (const MidiMessage& m)
    {
        if (m.isNoteOn())           return MidiMessage::getMidiNoteName (m.getNoteNumber(), true, true, 3) + " Velocity " + String (m.getVelocity());
        if (m.isNoteOff())          return MidiMessage::getMidiNoteName (m.getNoteNumber(), true, true, 3) + " Velocity " + String (m.getVelocity());
        if (m.isProgramChange())    return String (m.getProgramChangeNumber());
        if (m.isPitchWheel())       return String (m.getPitchWheelValue());
        if (m.isAftertouch())       return MidiMessage::getMidiNoteName (m.getNoteNumber(), true, true, 3) +  ": " + String (m.getAfterTouchValue());
        if (m.isChannelPressure())  return String (m.getChannelPressureValue());
        if (m.isController())       return String (m.getControllerValue());

        return {};
    }

    MidiListModel& messages;
    TableListBox table;
};

//==============================================================================
class MidiLoggerPluginDemoProcessor  :  public AudioProcessor,
                                        private Timer,
                                        public Component,
                                        private MidiInputCallback,
                                        private MidiKeyboardStateListener
{
public:
    MidiLoggerPluginDemoProcessor()
      : keyboardComponent(keyboardState, juce::MidiKeyboardComponent::verticalKeyboardFacingRight),
      //startTime(juce::Time::getMillisecondCounterHiRes() * 0.001),
      AudioProcessor (getBusesLayout())
    {
        state.addChild ({ "uiState", { { "width",  500 }, { "height", 400 } }, {} }, -1, nullptr);
        startTimerHz (60);
        //keyboardComponent.setMidiChannel(2);
    }

    ~MidiLoggerPluginDemoProcessor() override { 
      stopTimer(); 
      keyboardState.removeListener(this);
      deviceManager.removeMidiInputDeviceCallback(juce::MidiInput::getAvailableDevices()[midiInputList.getSelectedItemIndex()].identifier, this);
    }

    
    MidiKeyFinder Midi_Key_Finder_Util;

    // For Keyboard
    juce::AudioDeviceManager deviceManager;           // [1]
    juce::ComboBox midiInputList;                     // [2]
    juce::Label midiInputListLabel;
    int lastInputIndex = 0;                           // [3]
    bool isAddingFromMidiInput = false;               // [4]

    juce::MidiKeyboardState keyboardState;            // [5]
    juce::MidiKeyboardComponent keyboardComponent;    // [6]

    juce::TextEditor midiMessagesBox;
    double startTime;
    // End of Keyboard Variables

    // Some public functions for Keyboard
    void clearMessages()
    {
      midiMessagesBox.clear();
    }
    // End of public functions for Keyboard

    void processBlock (AudioBuffer<float>& audio,  MidiBuffer& midi) override { process (audio, midi); }
    void processBlock (AudioBuffer<double>& audio, MidiBuffer& midi) override { process (audio, midi); }

    bool isBusesLayoutSupported (const BusesLayout&) const override           { return true; }
    bool isMidiEffect() const override                                        { return true; }
    bool hasEditor() const override                                           { return true; }
    AudioProcessorEditor* createEditor() override                             { return new Editor (*this); }

    const String getName() const override                                     { return "MIDI Key Detector"; }
    bool acceptsMidi() const override                                         { return true; }
    bool producesMidi() const override                                        { return false; }
    double getTailLengthSeconds() const override                              { return 0.0; }

    int getNumPrograms() override                                             { return 0; }
    int getCurrentProgram() override                                          { return 0; }
    void setCurrentProgram (int) override                                     {}
    const String getProgramName (int) override                                { return {}; }
    void changeProgramName (int, const String&) override                      {}

    void prepareToPlay (double, int) override                                 {}
    void releaseResources() override                                          {}

    void getStateInformation (MemoryBlock& destData) override
    {
        if (auto xmlState = state.createXml())
            copyXmlToBinary (*xmlState, destData);
    }

    void setStateInformation (const void* data, int size) override
    {
        if (auto xmlState = getXmlFromBinary (data, size))
            state = ValueTree::fromXml (*xmlState);
    }


    // START KEYBOARD FUNCTIONS
    static juce::String getMidiMessageDescription(const juce::MidiMessage& m)
    {
      if (m.isNoteOn())           return "Note on " + juce::MidiMessage::getMidiNoteName(m.getNoteNumber(), true, true, 3);
      if (m.isNoteOff())          return "Note off " + juce::MidiMessage::getMidiNoteName(m.getNoteNumber(), true, true, 3);
      if (m.isProgramChange())    return "Program change " + juce::String(m.getProgramChangeNumber());
      if (m.isPitchWheel())       return "Pitch wheel " + juce::String(m.getPitchWheelValue());
      if (m.isAftertouch())       return "After touch " + juce::MidiMessage::getMidiNoteName(m.getNoteNumber(), true, true, 3) + ": " + juce::String(m.getAfterTouchValue());
      if (m.isChannelPressure())  return "Channel pressure " + juce::String(m.getChannelPressureValue());
      if (m.isAllNotesOff())      return "All notes off";
      if (m.isAllSoundOff())      return "All sound off";
      if (m.isMetaEvent())        return "Meta event";

      if (m.isController())
      {
        juce::String name(juce::MidiMessage::getControllerName(m.getControllerNumber()));

        if (name.isEmpty())
          name = "[" + juce::String(m.getControllerNumber()) + "]";

        return "Controller " + name + ": " + juce::String(m.getControllerValue());
      }

      return juce::String::toHexString(m.getRawData(), m.getRawDataSize());
    }

    void logMessage(const juce::String& m)
    {
      midiMessagesBox.moveCaretToEnd();
      midiMessagesBox.insertTextAtCaret(m + juce::newLine);
    }

    /** Starts listening to a MIDI input device, enabling it if necessary. */
    void setMidiInput(int index)
    {
      auto list = juce::MidiInput::getAvailableDevices();

      deviceManager.removeMidiInputDeviceCallback(list[lastInputIndex].identifier, this);

      auto newInput = list[index];

      if (!deviceManager.isMidiInputDeviceEnabled(newInput.identifier))
        deviceManager.setMidiInputDeviceEnabled(newInput.identifier, true);

      deviceManager.addMidiInputDeviceCallback(newInput.identifier, this);
      midiInputList.setSelectedId(index + 1, juce::dontSendNotification);

      lastInputIndex = index;
    }

    // These methods handle callbacks from the midi device + on-screen keyboard..
    void handleIncomingMidiMessage(juce::MidiInput* source, const juce::MidiMessage& message) override
    {
      const juce::ScopedValueSetter<bool> scopedInputFlag(isAddingFromMidiInput, true);
      keyboardState.processNextMidiEvent(message);
      postMessageToList(message, source->getName());
    }

    void handleNoteOn(juce::MidiKeyboardState*, int midiChannel, int midiNoteNumber, float velocity) override
    {
      if (!isAddingFromMidiInput)
      {
        auto m = juce::MidiMessage::noteOn(midiChannel, midiNoteNumber, velocity);
        m.setTimeStamp(juce::Time::getMillisecondCounterHiRes() * 0.001);
        postMessageToList(m, "On-Screen Keyboard");
      }
    }

    void handleNoteOff(juce::MidiKeyboardState*, int midiChannel, int midiNoteNumber, float /*velocity*/) override
    {
      if (!isAddingFromMidiInput)
      {
        auto m = juce::MidiMessage::noteOff(midiChannel, midiNoteNumber);
        m.setTimeStamp(juce::Time::getMillisecondCounterHiRes() * 0.001);
        postMessageToList(m, "On-Screen Keyboard");
      }
    }

    void postMessageToList(const juce::MidiMessage& message, const juce::String& source)
    {
      (new IncomingMessageCallback(this, message, source))->post();
    }

    void addMessageToList(const juce::MidiMessage& message, const juce::String& source)
    {

      midiMessagesBox.clear();

      auto time = message.getTimeStamp() - startTime;

      auto hours = ((int)(time / 3600.0)) % 24;
      auto minutes = ((int)(time / 60.0)) % 60;
      auto seconds = ((int)time) % 60;
      auto millis = ((int)(time * 1000.0)) % 1000;

      auto timecode = juce::String::formatted("%02d:%02d:%02d.%03d",
        hours,
        minutes,
        seconds,
        millis);

      auto description = getMidiMessageDescription(message);
      Midi_Key_Finder_Util.add_midi_message(message);
      auto test2 = Midi_Key_Finder_Util.get_keys();
      juce::String midiMessageString(test2); // [7]
      //juce::String midiMessageString(test2 + " | " + timecode + "  -  " + description + " (" + source + ")"); // [7]
      logMessage(midiMessageString);
    }

    // This is used to dispach an incoming message to the message thread
    class IncomingMessageCallback : public juce::CallbackMessage
    {
    public:
      IncomingMessageCallback(MidiLoggerPluginDemoProcessor* o, const juce::MidiMessage& m, const juce::String& s)
        : owner(o), message(m), source(s)
      {}

      void messageCallback() override
      {
        if (owner != nullptr)
          owner->addMessageToList(message, source);
      }


      Component::SafePointer<MidiLoggerPluginDemoProcessor> owner;
      juce::MidiMessage message;
      juce::String source;
    };


    // END KEYBOARD FUNCTIONS



private:


    class Editor  : public AudioProcessorEditor,
                    private Value::Listener
    {
    public:
        explicit Editor (MidiLoggerPluginDemoProcessor& ownerIn)
            : AudioProcessorEditor (ownerIn),
              owner2 (ownerIn),
              table (owner2.model, owner2.Midi_Key_Finder_Util)
        {
            //addAndMakeVisible (table);
            addAndMakeVisible (clearButton);
            //addAndMakeVisible (resetButton);

            setResizable (true, true);
            lastUIWidth .referTo (owner2.state.getChildWithName ("uiState").getPropertyAsValue ("width",  nullptr));
            lastUIHeight.referTo (owner2.state.getChildWithName ("uiState").getPropertyAsValue ("height", nullptr));
            setSize (lastUIWidth.getValue(), lastUIHeight.getValue());

            lastUIWidth. addListener (this);
            lastUIHeight.addListener (this);

            
            clearButton.onClick = [&] { owner2.Midi_Key_Finder_Util.reset(); owner2.midiMessagesBox.clear(); };
            


            //FOR KEYBOARD
            owner2.midiInputListLabel.setText("MIDI Input:", juce::dontSendNotification);
            owner2.midiInputListLabel.attachToComponent(&owner2.midiInputList, true);

            addAndMakeVisible(owner2.midiInputList);
            owner2.midiInputList.setTextWhenNoChoicesAvailable("No MIDI Inputs Enabled");
            auto midiInputs = juce::MidiInput::getAvailableDevices();

            juce::StringArray midiInputNames;

            for (auto input : midiInputs)
              midiInputNames.add(input.name);

            owner2.midiInputList.addItemList(midiInputNames, 1);
            owner2.midiInputList.onChange = [this] { owner2.setMidiInput(owner2.midiInputList.getSelectedItemIndex()); };

            // find the first enabled device and use that by default
            for (auto input : midiInputs)
            {
              if (owner2.deviceManager.isMidiInputDeviceEnabled(input.identifier))
              {
                owner2.setMidiInput(midiInputs.indexOf(input));
                break;
              }
            }

            // if no enabled devices were found just use the first one in the list
            if (owner2.midiInputList.getSelectedId() == 0)
              owner2.setMidiInput(0);

            addAndMakeVisible(owner2.keyboardComponent);
            owner2.keyboardState.addListener(&owner2);

            addAndMakeVisible(owner2.midiMessagesBox);
            owner2.midiMessagesBox.setMultiLine(true);
            owner2.midiMessagesBox.setReturnKeyStartsNewLine(true);
            owner2.midiMessagesBox.setReadOnly(true);
            owner2.midiMessagesBox.setScrollbarsShown(true);
            owner2.midiMessagesBox.setCaretVisible(false);
            owner2.midiMessagesBox.setPopupMenuEnabled(true);
            owner2.midiMessagesBox.setFont(Font(20.0f, 1));
            owner2.midiMessagesBox.setColour(juce::TextEditor::backgroundColourId, juce::Colour(0x32ffffff));
            owner2.midiMessagesBox.setColour(juce::TextEditor::outlineColourId, juce::Colour(0x1c000000));
            owner2.midiMessagesBox.setColour(juce::TextEditor::shadowColourId, juce::Colour(0x16000000));


        }

        void paint (Graphics& g) override
        {
            g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
        }

        void resized() override
        {
            auto bounds = getLocalBounds();


            owner2.midiInputList.setBounds(bounds.removeFromTop(36).removeFromRight(getWidth() - 150).reduced(8));
            owner2.keyboardComponent.setBounds(bounds.removeFromLeft(120).reduced(8));
            owner2.midiMessagesBox.setBounds(bounds.removeFromLeft(250).reduced(8));

            //table.setBounds(bounds.removeFromLeft(300).reduced(8));
            clearButton.setBounds(bounds.removeFromLeft(100).withSizeKeepingCentre(100, getHeight() - 50).reduced(8,0));
            //resetButton.setBounds(bounds.removeFromLeft(80).withSizeKeepingCentre(50, 24));
            

            lastUIWidth  = getWidth();
            lastUIHeight = getHeight();
        }

    private:


        void valueChanged (Value&) override
        {
            setSize (lastUIWidth.getValue(), lastUIHeight.getValue());
        }

        MidiLoggerPluginDemoProcessor& owner2;

        MidiTable table;
        TextButton clearButton { "Clear" };
        TextButton resetButton { "RESET" };

        Value lastUIWidth, lastUIHeight;


    };

    void timerCallback() override
    {
        std::vector<MidiMessage> messages;
        queue.pop (std::back_inserter (messages));
        //model.addMessages (messages.begin(), messages.end());
        addMIDIMessages(messages.begin(), messages.end());
    }


    // Send midi in to 
    template <typename It>
    void addMIDIMessages(It begin, It end)
    {
      const auto numNewMessages = (int)std::distance(begin, end);
      const auto numToAdd = juce::jmin(numToStore2, numNewMessages);
      const auto numToRemove = jmax(0, (int)messages2.size() + numToAdd - numToStore2);
      messages2.erase(messages2.begin(), std::next(messages2.begin(), numToRemove));
      messages2.insert(messages2.end(), std::prev(end, numToAdd), end);
      
      for (MidiMessage m : messages2) {
        addMessageToList(m, "Midi-in");
      }
      messages2.clear();
      //midiMessagesBox.clear();

    }

    static constexpr auto numToStore2 = 1000;
    std::vector<MidiMessage> messages2;


    template <typename Element>
    void process (AudioBuffer<Element>& audio, MidiBuffer& midi)
    {
        audio.clear();
        queue.push (midi);
    }

    static BusesProperties getBusesLayout()
    {
        // Live doesn't like to load midi-only plugins, so we add an audio output there.
        return PluginHostType().isAbletonLive() ? BusesProperties().withOutput ("out", AudioChannelSet::stereo())
                                                : BusesProperties();
    }

    ValueTree state { "state" };
    MidiQueue queue;
    MidiListModel model; // The data to show in the UI. We keep it around in the processor so that
                         // the view is persistent even when the plugin UI is closed and reopened.





    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MidiLoggerPluginDemoProcessor)
};
