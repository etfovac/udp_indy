object ClientForm: TClientForm
  Left = 0
  Top = 0
  Caption = 'Client'
  ClientHeight = 614
  ClientWidth = 561
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnCreate = FormCreate
  DesignSize = (
    561
    614)
  TextHeight = 15
  object Memo1: TMemo
    Left = 8
    Top = 157
    Width = 545
    Height = 432
    Anchors = [akLeft, akTop, akRight, akBottom]
    Lines.Strings = (
      'Memo1')
    TabOrder = 0
    OnChange = Memo1Change
  end
  object Enable: TCheckBox
    Left = 8
    Top = 8
    Width = 97
    Height = 17
    Caption = 'Enable'
    TabOrder = 1
    OnClick = EnableClick
  end
  object BufferSize: TEdit
    Left = 8
    Top = 120
    Width = 113
    Height = 23
    TabOrder = 2
    TextHint = 'BufferSize'
    OnChange = BufferSizeChange
  end
  object BroadcastProperties: TGroupBox
    Left = 360
    Top = 8
    Width = 185
    Height = 79
    Caption = 'Broadcast Properties'
    TabOrder = 3
    object BPort: TEdit
      Left = 0
      Top = 47
      Width = 185
      Height = 23
      TabOrder = 0
      TextHint = 'Port'
      OnChange = PortChange
    end
    object Broadcast: TCheckBox
      Left = 3
      Top = 19
      Width = 97
      Height = 17
      Caption = 'Broadcast'
      TabOrder = 1
      OnClick = BroadcastClick
    end
    object BroadcastIndicator: TRadioButton
      Left = 136
      Top = 19
      Width = 25
      Height = 17
      TabOrder = 2
    end
  end
  object ServerProperties: TGroupBox
    Left = 152
    Top = 8
    Width = 185
    Height = 79
    Caption = 'Server Properties (Send To)'
    TabOrder = 4
    object Address: TEdit
      Left = 0
      Top = 16
      Width = 185
      Height = 23
      TabOrder = 0
      TextHint = 'Address'
      OnChange = AddressChange
    end
    object Port: TEdit
      Left = 0
      Top = 45
      Width = 185
      Height = 23
      TabOrder = 1
      TextHint = 'Port'
      OnChange = PortChange
    end
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 595
    Width = 561
    Height = 19
    Panels = <>
    SimplePanel = True
    ExplicitLeft = 248
    ExplicitTop = 592
    ExplicitWidth = 0
  end
  object RepeatProperties: TGroupBox
    Left = 152
    Top = 94
    Width = 393
    Height = 57
    Caption = 'Repeat Properties'
    TabOrder = 6
    object Period: TEdit
      Left = 3
      Top = 26
      Width = 113
      Height = 23
      TabOrder = 0
      TextHint = 'Timer->Interval'
      OnChange = PeriodChange
    end
  end
  object IdUDPClient1: TIdUDPClient
    Host = '192.168.0.11'
    Port = 0
    Left = 216
    Top = 256
  end
  object ClientTimer: TTimer
    OnTimer = ClientTimerTimer
    Left = 296
    Top = 256
  end
end
