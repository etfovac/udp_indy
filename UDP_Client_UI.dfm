object ClientForm: TClientForm
  Left = 0
  Top = 0
  Caption = 'UDP Client'
  ClientHeight = 605
  ClientWidth = 346
  Color = clBtnFace
  Constraints.MinHeight = 600
  Constraints.MinWidth = 345
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Visible = True
  OnCreate = FormCreate
  TextHeight = 15
  object Memo1: TMemo
    Left = 0
    Top = 160
    Width = 346
    Height = 426
    Align = alClient
    Constraints.MinHeight = 390
    Constraints.MinWidth = 340
    Lines.Strings = (
      'Memo1')
    ScrollBars = ssBoth
    TabOrder = 0
    OnChange = Memo1Change
    ExplicitLeft = 3
    ExplicitTop = 169
    ExplicitWidth = 340
    ExplicitHeight = 415
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 586
    Width = 346
    Height = 19
    Panels = <>
    SimplePanel = True
    ExplicitLeft = -2
    ExplicitTop = 593
    ExplicitWidth = 340
  end
  object Controls: TGroupBox
    Left = 0
    Top = 0
    Width = 346
    Height = 160
    Align = alTop
    Caption = 'Controls'
    Constraints.MinHeight = 160
    TabOrder = 2
    ExplicitLeft = 8
    ExplicitTop = 8
    ExplicitWidth = 340
    object Enable: TCheckBox
      Left = 9
      Top = 23
      Width = 57
      Height = 17
      Caption = 'Enable'
      TabOrder = 0
      OnClick = EnableClick
    end
    object BroadcastProperties: TGroupBox
      Left = 147
      Top = 82
      Width = 185
      Height = 73
      Caption = 'Broadcast Properties'
      TabOrder = 1
      object BPort: TEdit
        Left = 0
        Top = 45
        Width = 185
        Height = 23
        Hint = 'Broadcast Port'
        ParentShowHint = False
        ShowHint = True
        TabOrder = 0
        TextHint = 'Broadcast Port'
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
    end
    object BufferProperties: TGroupBox
      Left = 3
      Top = 53
      Width = 138
      Height = 50
      Caption = 'Buffer'
      TabOrder = 2
      object Label1: TLabel
        Left = 48
        Top = 16
        Width = 34
        Height = 15
        Caption = 'Label1'
      end
      object BufferSize: TEdit
        Left = 0
        Top = 17
        Width = 138
        Height = 23
        TabOrder = 0
        TextHint = 'BufferSize'
        OnChange = BufferSizeChange
      end
    end
    object RepeatProperties: TGroupBox
      Left = 3
      Top = 104
      Width = 138
      Height = 50
      Caption = 'Repeat Properties'
      TabOrder = 3
      object ms: TLabel
        Left = 111
        Top = 24
        Width = 16
        Height = 15
        Caption = 'ms'
      end
      object Period: TEdit
        Left = 2
        Top = 17
        Width = 103
        Height = 23
        TabOrder = 0
        TextHint = 'Timer->Interval'
        OnChange = PeriodChange
      end
    end
    object ServerProperties: TGroupBox
      Left = 147
      Top = 8
      Width = 185
      Height = 73
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
  end
  object IdUDPClient1: TIdUDPClient
    Host = '192.168.0.11'
    Port = 0
    Left = 216
    Top = 256
  end
  object ClientTimer: TTimer
    OnTimer = ClientTimer_Timeout
    Left = 296
    Top = 256
  end
end
