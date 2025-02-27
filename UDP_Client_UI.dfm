object ClientForm: TClientForm
  Left = 0
  Top = 0
  Caption = 'UDP Client'
  ClientHeight = 601
  ClientWidth = 344
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Visible = True
  OnCreate = FormCreate
  TextHeight = 15
  object Controls: TGroupBox
    AlignWithMargins = True
    Left = 3
    Top = 3
    Width = 338
    Height = 158
    Align = alTop
    Caption = 'Controls'
    TabOrder = 2
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
      object Label2: TLabel
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
  object Memo1: TMemo
    AlignWithMargins = True
    Left = 3
    Top = 163
    Width = 338
    Height = 416
    Align = alBottom
    Lines.Strings = (
      'Memo1')
    TabOrder = 0
    OnChange = Memo1Change
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 582
    Width = 344
    Height = 19
    Panels = <>
    SimplePanel = True
    ExplicitTop = 587
    ExplicitWidth = 550
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
