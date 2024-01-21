object Server: TServer
  Left = 0
  Top = 0
  Caption = 'Server'
  ClientHeight = 442
  ClientWidth = 771
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnCreate = FormCreate
  TextHeight = 15
  object Enable: TCheckBox
    Left = 0
    Top = 8
    Width = 97
    Height = 17
    Caption = 'Enable'
    TabOrder = 0
    OnClick = EnableClick
  end
  object Status: TEdit
    Left = 0
    Top = 411
    Width = 320
    Height = 23
    TabOrder = 1
  end
  object Memo1: TMemo
    Left = 0
    Top = 64
    Width = 763
    Height = 341
    Lines.Strings = (
      'Memo1')
    TabOrder = 2
  end
  object IPs: TEdit
    Left = 232
    Top = 18
    Width = 169
    Height = 23
    TabOrder = 3
  end
  object Ports: TEdit
    Left = 424
    Top = 18
    Width = 169
    Height = 23
    TabOrder = 4
  end
  object IdUDPServer1: TIdUDPServer
    Bindings = <>
    DefaultPort = 0
    Left = 64
    Top = 8
  end
end
