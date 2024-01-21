object ClientForm: TClientForm
  Left = 0
  Top = 0
  Caption = 'Client'
  ClientHeight = 441
  ClientWidth = 624
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnCreate = FormCreate
  TextHeight = 15
  object Memo1: TMemo
    Left = 168
    Top = 216
    Width = 185
    Height = 25
    Lines.Strings = (
      'Memo1')
    TabOrder = 0
  end
  object Status: TEdit
    Left = 168
    Top = 120
    Width = 185
    Height = 23
    TabOrder = 1
    OnChange = StatusChange
  end
  object Enable: TCheckBox
    Left = 168
    Top = 168
    Width = 97
    Height = 17
    Caption = 'Enable'
    TabOrder = 2
    OnClick = EnableClick
  end
  object Address: TEdit
    Left = 168
    Top = 87
    Width = 185
    Height = 23
    TabOrder = 3
    Text = '127.0.0.1'
    OnChange = AddressChange
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
