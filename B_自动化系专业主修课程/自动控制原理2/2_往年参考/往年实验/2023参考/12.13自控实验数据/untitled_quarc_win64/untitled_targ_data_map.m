    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 7;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc paramMap
        ;%
        paramMap.nSections           = nTotSects;
        paramMap.sectIdxOffset       = sectIdxOffset;
            paramMap.sections(nTotSects) = dumSection; %prealloc
        paramMap.nTotData            = -1;

        ;%
        ;% Auto data (untitled_P)
        ;%
            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% untitled_P.K
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% untitled_P.CompareToConstant_const
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 4;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% untitled_P.HILWriteAnalog_channels
                    section.data(1).logicalSrcIdx = 2;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 40;
            section.data(40)  = dumData; %prealloc

                    ;% untitled_P.Gain4_Gain
                    section.data(1).logicalSrcIdx = 3;
                    section.data(1).dtTransOffset = 0;

                    ;% untitled_P.HILInitialize_OOTerminate
                    section.data(2).logicalSrcIdx = 4;
                    section.data(2).dtTransOffset = 4;

                    ;% untitled_P.HILInitialize_OOExit
                    section.data(3).logicalSrcIdx = 5;
                    section.data(3).dtTransOffset = 5;

                    ;% untitled_P.HILInitialize_OOStart
                    section.data(4).logicalSrcIdx = 6;
                    section.data(4).dtTransOffset = 6;

                    ;% untitled_P.HILInitialize_OOEnter
                    section.data(5).logicalSrcIdx = 7;
                    section.data(5).dtTransOffset = 7;

                    ;% untitled_P.HILInitialize_AOFinal
                    section.data(6).logicalSrcIdx = 8;
                    section.data(6).dtTransOffset = 8;

                    ;% untitled_P.HILInitialize_POFinal
                    section.data(7).logicalSrcIdx = 9;
                    section.data(7).dtTransOffset = 9;

                    ;% untitled_P.HILInitialize_OOFinal
                    section.data(8).logicalSrcIdx = 10;
                    section.data(8).dtTransOffset = 10;

                    ;% untitled_P.HILInitialize_AIHigh
                    section.data(9).logicalSrcIdx = 11;
                    section.data(9).dtTransOffset = 13;

                    ;% untitled_P.HILInitialize_AILow
                    section.data(10).logicalSrcIdx = 12;
                    section.data(10).dtTransOffset = 14;

                    ;% untitled_P.HILInitialize_AOHigh
                    section.data(11).logicalSrcIdx = 13;
                    section.data(11).dtTransOffset = 15;

                    ;% untitled_P.HILInitialize_AOLow
                    section.data(12).logicalSrcIdx = 14;
                    section.data(12).dtTransOffset = 16;

                    ;% untitled_P.HILInitialize_AOInitial
                    section.data(13).logicalSrcIdx = 15;
                    section.data(13).dtTransOffset = 17;

                    ;% untitled_P.HILInitialize_AOWatchdog
                    section.data(14).logicalSrcIdx = 16;
                    section.data(14).dtTransOffset = 18;

                    ;% untitled_P.HILInitialize_POFrequency
                    section.data(15).logicalSrcIdx = 17;
                    section.data(15).dtTransOffset = 19;

                    ;% untitled_P.HILInitialize_POLeading
                    section.data(16).logicalSrcIdx = 18;
                    section.data(16).dtTransOffset = 20;

                    ;% untitled_P.HILInitialize_POTrailing
                    section.data(17).logicalSrcIdx = 19;
                    section.data(17).dtTransOffset = 21;

                    ;% untitled_P.HILInitialize_POInitial
                    section.data(18).logicalSrcIdx = 20;
                    section.data(18).dtTransOffset = 22;

                    ;% untitled_P.HILInitialize_OOInitial
                    section.data(19).logicalSrcIdx = 21;
                    section.data(19).dtTransOffset = 23;

                    ;% untitled_P.HILInitialize_OOWatchdog
                    section.data(20).logicalSrcIdx = 22;
                    section.data(20).dtTransOffset = 26;

                    ;% untitled_P.Gain2_Gain
                    section.data(21).logicalSrcIdx = 23;
                    section.data(21).dtTransOffset = 29;

                    ;% untitled_P.Constant_Value
                    section.data(22).logicalSrcIdx = 24;
                    section.data(22).dtTransOffset = 30;

                    ;% untitled_P.Bias_Bias
                    section.data(23).logicalSrcIdx = 25;
                    section.data(23).dtTransOffset = 31;

                    ;% untitled_P.Constant1_Value
                    section.data(24).logicalSrcIdx = 26;
                    section.data(24).dtTransOffset = 32;

                    ;% untitled_P.SignalGenerator_Amplitude
                    section.data(25).logicalSrcIdx = 27;
                    section.data(25).dtTransOffset = 33;

                    ;% untitled_P.SignalGenerator_Frequency
                    section.data(26).logicalSrcIdx = 28;
                    section.data(26).dtTransOffset = 34;

                    ;% untitled_P.Gain3_Gain
                    section.data(27).logicalSrcIdx = 29;
                    section.data(27).dtTransOffset = 35;

                    ;% untitled_P.Gain1_Gain
                    section.data(28).logicalSrcIdx = 30;
                    section.data(28).dtTransOffset = 36;

                    ;% untitled_P.Gain1_Gain_j
                    section.data(29).logicalSrcIdx = 31;
                    section.data(29).dtTransOffset = 37;

                    ;% untitled_P.TransferFcn_A
                    section.data(30).logicalSrcIdx = 32;
                    section.data(30).dtTransOffset = 38;

                    ;% untitled_P.TransferFcn_C
                    section.data(31).logicalSrcIdx = 33;
                    section.data(31).dtTransOffset = 39;

                    ;% untitled_P.TransferFcn_D
                    section.data(32).logicalSrcIdx = 34;
                    section.data(32).dtTransOffset = 40;

                    ;% untitled_P.TransferFcn1_A
                    section.data(33).logicalSrcIdx = 35;
                    section.data(33).dtTransOffset = 41;

                    ;% untitled_P.TransferFcn1_C
                    section.data(34).logicalSrcIdx = 36;
                    section.data(34).dtTransOffset = 42;

                    ;% untitled_P.TransferFcn1_D
                    section.data(35).logicalSrcIdx = 37;
                    section.data(35).dtTransOffset = 43;

                    ;% untitled_P.Saturation_UpperSat
                    section.data(36).logicalSrcIdx = 38;
                    section.data(36).dtTransOffset = 44;

                    ;% untitled_P.Saturation_LowerSat
                    section.data(37).logicalSrcIdx = 39;
                    section.data(37).dtTransOffset = 45;

                    ;% untitled_P.Gain_Gain
                    section.data(38).logicalSrcIdx = 40;
                    section.data(38).dtTransOffset = 46;

                    ;% untitled_P.Gain_Gain_a
                    section.data(39).logicalSrcIdx = 41;
                    section.data(39).dtTransOffset = 47;

                    ;% untitled_P.Gain_Gain_n
                    section.data(40).logicalSrcIdx = 42;
                    section.data(40).dtTransOffset = 48;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 8;
            section.data(8)  = dumData; %prealloc

                    ;% untitled_P.HILInitialize_CKChannels
                    section.data(1).logicalSrcIdx = 43;
                    section.data(1).dtTransOffset = 0;

                    ;% untitled_P.HILInitialize_DOWatchdog
                    section.data(2).logicalSrcIdx = 44;
                    section.data(2).dtTransOffset = 1;

                    ;% untitled_P.HILInitialize_EIInitial
                    section.data(3).logicalSrcIdx = 45;
                    section.data(3).dtTransOffset = 2;

                    ;% untitled_P.HILInitialize_POModes
                    section.data(4).logicalSrcIdx = 46;
                    section.data(4).dtTransOffset = 3;

                    ;% untitled_P.HILInitialize_POConfiguration
                    section.data(5).logicalSrcIdx = 47;
                    section.data(5).dtTransOffset = 4;

                    ;% untitled_P.HILInitialize_POAlignment
                    section.data(6).logicalSrcIdx = 48;
                    section.data(6).dtTransOffset = 5;

                    ;% untitled_P.HILInitialize_POPolarity
                    section.data(7).logicalSrcIdx = 49;
                    section.data(7).dtTransOffset = 6;

                    ;% untitled_P.HILReadEncoderTimebase_Clock
                    section.data(8).logicalSrcIdx = 50;
                    section.data(8).dtTransOffset = 7;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section

            section.nData     = 8;
            section.data(8)  = dumData; %prealloc

                    ;% untitled_P.HILInitialize_AIChannels
                    section.data(1).logicalSrcIdx = 51;
                    section.data(1).dtTransOffset = 0;

                    ;% untitled_P.HILInitialize_AOChannels
                    section.data(2).logicalSrcIdx = 52;
                    section.data(2).dtTransOffset = 1;

                    ;% untitled_P.HILInitialize_DOChannels
                    section.data(3).logicalSrcIdx = 53;
                    section.data(3).dtTransOffset = 2;

                    ;% untitled_P.HILInitialize_EIChannels
                    section.data(4).logicalSrcIdx = 54;
                    section.data(4).dtTransOffset = 3;

                    ;% untitled_P.HILInitialize_EIQuadrature
                    section.data(5).logicalSrcIdx = 55;
                    section.data(5).dtTransOffset = 5;

                    ;% untitled_P.HILInitialize_OOChannels
                    section.data(6).logicalSrcIdx = 56;
                    section.data(6).dtTransOffset = 6;

                    ;% untitled_P.HILReadEncoderTimebase_Channels
                    section.data(7).logicalSrcIdx = 57;
                    section.data(7).dtTransOffset = 9;

                    ;% untitled_P.HILReadEncoderTimebase_SamplesI
                    section.data(8).logicalSrcIdx = 58;
                    section.data(8).dtTransOffset = 11;

            nTotData = nTotData + section.nData;
            paramMap.sections(5) = section;
            clear section

            section.nData     = 37;
            section.data(37)  = dumData; %prealloc

                    ;% untitled_P.HILInitialize_Active
                    section.data(1).logicalSrcIdx = 59;
                    section.data(1).dtTransOffset = 0;

                    ;% untitled_P.HILInitialize_AOTerminate
                    section.data(2).logicalSrcIdx = 60;
                    section.data(2).dtTransOffset = 1;

                    ;% untitled_P.HILInitialize_AOExit
                    section.data(3).logicalSrcIdx = 61;
                    section.data(3).dtTransOffset = 2;

                    ;% untitled_P.HILInitialize_DOTerminate
                    section.data(4).logicalSrcIdx = 62;
                    section.data(4).dtTransOffset = 3;

                    ;% untitled_P.HILInitialize_DOExit
                    section.data(5).logicalSrcIdx = 63;
                    section.data(5).dtTransOffset = 4;

                    ;% untitled_P.HILInitialize_POTerminate
                    section.data(6).logicalSrcIdx = 64;
                    section.data(6).dtTransOffset = 5;

                    ;% untitled_P.HILInitialize_POExit
                    section.data(7).logicalSrcIdx = 65;
                    section.data(7).dtTransOffset = 6;

                    ;% untitled_P.HILInitialize_CKPStart
                    section.data(8).logicalSrcIdx = 66;
                    section.data(8).dtTransOffset = 7;

                    ;% untitled_P.HILInitialize_CKPEnter
                    section.data(9).logicalSrcIdx = 67;
                    section.data(9).dtTransOffset = 8;

                    ;% untitled_P.HILInitialize_CKStart
                    section.data(10).logicalSrcIdx = 68;
                    section.data(10).dtTransOffset = 9;

                    ;% untitled_P.HILInitialize_CKEnter
                    section.data(11).logicalSrcIdx = 69;
                    section.data(11).dtTransOffset = 10;

                    ;% untitled_P.HILInitialize_AIPStart
                    section.data(12).logicalSrcIdx = 70;
                    section.data(12).dtTransOffset = 11;

                    ;% untitled_P.HILInitialize_AIPEnter
                    section.data(13).logicalSrcIdx = 71;
                    section.data(13).dtTransOffset = 12;

                    ;% untitled_P.HILInitialize_AOPStart
                    section.data(14).logicalSrcIdx = 72;
                    section.data(14).dtTransOffset = 13;

                    ;% untitled_P.HILInitialize_AOPEnter
                    section.data(15).logicalSrcIdx = 73;
                    section.data(15).dtTransOffset = 14;

                    ;% untitled_P.HILInitialize_AOStart
                    section.data(16).logicalSrcIdx = 74;
                    section.data(16).dtTransOffset = 15;

                    ;% untitled_P.HILInitialize_AOEnter
                    section.data(17).logicalSrcIdx = 75;
                    section.data(17).dtTransOffset = 16;

                    ;% untitled_P.HILInitialize_AOReset
                    section.data(18).logicalSrcIdx = 76;
                    section.data(18).dtTransOffset = 17;

                    ;% untitled_P.HILInitialize_DOPStart
                    section.data(19).logicalSrcIdx = 77;
                    section.data(19).dtTransOffset = 18;

                    ;% untitled_P.HILInitialize_DOPEnter
                    section.data(20).logicalSrcIdx = 78;
                    section.data(20).dtTransOffset = 19;

                    ;% untitled_P.HILInitialize_DOStart
                    section.data(21).logicalSrcIdx = 79;
                    section.data(21).dtTransOffset = 20;

                    ;% untitled_P.HILInitialize_DOEnter
                    section.data(22).logicalSrcIdx = 80;
                    section.data(22).dtTransOffset = 21;

                    ;% untitled_P.HILInitialize_DOReset
                    section.data(23).logicalSrcIdx = 81;
                    section.data(23).dtTransOffset = 22;

                    ;% untitled_P.HILInitialize_EIPStart
                    section.data(24).logicalSrcIdx = 82;
                    section.data(24).dtTransOffset = 23;

                    ;% untitled_P.HILInitialize_EIPEnter
                    section.data(25).logicalSrcIdx = 83;
                    section.data(25).dtTransOffset = 24;

                    ;% untitled_P.HILInitialize_EIStart
                    section.data(26).logicalSrcIdx = 84;
                    section.data(26).dtTransOffset = 25;

                    ;% untitled_P.HILInitialize_EIEnter
                    section.data(27).logicalSrcIdx = 85;
                    section.data(27).dtTransOffset = 26;

                    ;% untitled_P.HILInitialize_POPStart
                    section.data(28).logicalSrcIdx = 86;
                    section.data(28).dtTransOffset = 27;

                    ;% untitled_P.HILInitialize_POPEnter
                    section.data(29).logicalSrcIdx = 87;
                    section.data(29).dtTransOffset = 28;

                    ;% untitled_P.HILInitialize_POStart
                    section.data(30).logicalSrcIdx = 88;
                    section.data(30).dtTransOffset = 29;

                    ;% untitled_P.HILInitialize_POEnter
                    section.data(31).logicalSrcIdx = 89;
                    section.data(31).dtTransOffset = 30;

                    ;% untitled_P.HILInitialize_POReset
                    section.data(32).logicalSrcIdx = 90;
                    section.data(32).dtTransOffset = 31;

                    ;% untitled_P.HILInitialize_OOReset
                    section.data(33).logicalSrcIdx = 91;
                    section.data(33).dtTransOffset = 32;

                    ;% untitled_P.HILInitialize_DOFinal
                    section.data(34).logicalSrcIdx = 92;
                    section.data(34).dtTransOffset = 33;

                    ;% untitled_P.HILInitialize_DOInitial
                    section.data(35).logicalSrcIdx = 93;
                    section.data(35).dtTransOffset = 34;

                    ;% untitled_P.HILReadEncoderTimebase_Active
                    section.data(36).logicalSrcIdx = 94;
                    section.data(36).dtTransOffset = 35;

                    ;% untitled_P.HILWriteAnalog_Active
                    section.data(37).logicalSrcIdx = 95;
                    section.data(37).dtTransOffset = 36;

            nTotData = nTotData + section.nData;
            paramMap.sections(6) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% untitled_P.HILReadEncoderTimebase_Overflow
                    section.data(1).logicalSrcIdx = 96;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(7) = section;
            clear section


            ;%
            ;% Non-auto Data (parameter)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        paramMap.nTotData = nTotData;



    ;%**************************
    ;% Create Block Output Map *
    ;%**************************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 2;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc sigMap
        ;%
        sigMap.nSections           = nTotSects;
        sigMap.sectIdxOffset       = sectIdxOffset;
            sigMap.sections(nTotSects) = dumSection; %prealloc
        sigMap.nTotData            = -1;

        ;%
        ;% Auto data (untitled_B)
        ;%
            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% untitled_B.Bias
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% untitled_B.Gain1
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% untitled_B.MultiportSwitch
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% untitled_B.Gain
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% untitled_B.Gain_j
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% untitled_B.Gain_f
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% untitled_B.Compare
                    section.data(1).logicalSrcIdx = 6;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(2) = section;
            clear section


            ;%
            ;% Non-auto Data (signal)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        sigMap.nTotData = nTotData;



    ;%*******************
    ;% Create DWork Map *
    ;%*******************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 5;
        sectIdxOffset = 2;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc dworkMap
        ;%
        dworkMap.nSections           = nTotSects;
        dworkMap.sectIdxOffset       = sectIdxOffset;
            dworkMap.sections(nTotSects) = dumSection; %prealloc
        dworkMap.nTotData            = -1;

        ;%
        ;% Auto data (untitled_DW)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% untitled_DW.HILInitialize_FilterFrequency
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% untitled_DW.HILInitialize_Card
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% untitled_DW.HILReadEncoderTimebase_Task
                    section.data(1).logicalSrcIdx = 2;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% untitled_DW.HILWriteAnalog_PWORK
                    section.data(1).logicalSrcIdx = 3;
                    section.data(1).dtTransOffset = 0;

                    ;% untitled_DW.Scope_PWORK.LoggedData
                    section.data(2).logicalSrcIdx = 4;
                    section.data(2).dtTransOffset = 1;

                    ;% untitled_DW.Scope1_PWORK.LoggedData
                    section.data(3).logicalSrcIdx = 5;
                    section.data(3).dtTransOffset = 2;

                    ;% untitled_DW.Scope2_PWORK.LoggedData
                    section.data(4).logicalSrcIdx = 6;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% untitled_DW.HILInitialize_ClockModes
                    section.data(1).logicalSrcIdx = 7;
                    section.data(1).dtTransOffset = 0;

                    ;% untitled_DW.HILInitialize_DOStates
                    section.data(2).logicalSrcIdx = 8;
                    section.data(2).dtTransOffset = 1;

                    ;% untitled_DW.HILInitialize_QuadratureModes
                    section.data(3).logicalSrcIdx = 9;
                    section.data(3).dtTransOffset = 2;

                    ;% untitled_DW.HILInitialize_InitialEICounts
                    section.data(4).logicalSrcIdx = 10;
                    section.data(4).dtTransOffset = 4;

                    ;% untitled_DW.HILReadEncoderTimebase_Buffer
                    section.data(5).logicalSrcIdx = 11;
                    section.data(5).dtTransOffset = 6;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section


            ;%
            ;% Non-auto Data (dwork)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        dworkMap.nTotData = nTotData;



    ;%
    ;% Add individual maps to base struct.
    ;%

    targMap.paramMap  = paramMap;
    targMap.signalMap = sigMap;
    targMap.dworkMap  = dworkMap;

    ;%
    ;% Add checksums to base struct.
    ;%


    targMap.checksum0 = 448622629;
    targMap.checksum1 = 4052225775;
    targMap.checksum2 = 306397325;
    targMap.checksum3 = 767809918;

