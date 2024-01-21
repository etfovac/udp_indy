object ClientForm: TClientForm
  Left = 0
  Top = 0
  Caption = 'Client'
  ClientHeight = 440
  ClientWidth = 620
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnCreate = FormCreate
  TextHeight = 15
  object Memo1: TMemo
    Left = 112
    Top = 112
    Width = 489
    Height = 89
    Lines.Strings = (
      'Memo1')
    TabOrder = 0
    OnChange = Memo1Change
  end
  object Status: TEdit
    Left = 8
    Top = 409
    Width = 185
    Height = 23
    TabOrder = 1
  end
  object Enable: TCheckBox
    Left = 8
    Top = 8
    Width = 97
    Height = 17
    Caption = 'Enable'
    TabOrder = 2
    OnClick = EnableClick
  end
  object Address: TEdit
    Left = 152
    Top = 23
    Width = 185
    Height = 23
    TabOrder = 3
    Text = '127.0.0.1'
    OnChange = AddressChange
  end
  object Port: TEdit
    Left = 152
    Top = 52
    Width = 185
    Height = 23
    TabOrder = 4
    OnChange = PortChange
  end
  object Period: TEdit
    Left = 8
    Top = 220
    Width = 185
    Height = 23
    TabOrder = 5
    OnChange = PeriodChange
  end
  object IdUDPClient1: TIdUDPClient
    Host = '192.168.0.11'
    Port = 50000
    Left = 48
    Top = 56
  end
  object ClientTimer: TTimer
    OnTimer = ClientTimerTimer
    Left = 48
    Top = 136
  end
end
