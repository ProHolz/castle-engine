{%MainUnit castlepropedits.pas}
{
  Copyright 2018-2022 Michalis Kamburelis.

  This file is part of "Castle Game Engine".

  "Castle Game Engine" is free software; see the file COPYING.txt,
  included in this distribution, for details about the copyright.

  "Castle Game Engine" is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

  ----------------------------------------------------------------------------
}

{ Vector property editors. }

{ TCastleVector2PropertyEditor ------------------------------------------------- }

type
  TCastleVector2PropertyEditor = class(TSubPropertiesEditor)
  strict protected
    procedure SetAllValues(const NewValue: TVector2);
  public
    function GetAttributes: TPropertyAttributes; override;
    function GetName: shortstring; override;
    function GetValue: String; override;
    procedure SetValue(const NewValue: String); override;
    { Unsure if this is necessary to be overridden anymore.
      It is used by default ValueIsStreamed implementation, but we override that. }
    function GetDefaultValue: String; override;
    { Determines if value is displayed bold or not.

      Default implementation looks at GetDefaultValue but also at HasDefaultValue
      value, which is always true for our vectors but TPropertyEditor.HasDefaultValue
      will be always false.

      So we override it to check using TCastleVectorXxPersistent.HasDefaultValue. }
    function ValueIsStreamed: boolean; override;
    function AllEqual: Boolean; override;
  end;

function TCastleVector2PropertyEditor.GetAttributes: TPropertyAttributes;
begin
  Result := inherited GetAttributes + [paRevertable]
    // our SetValue allows to set value from string
    - [paReadOnly];
end;

function TCastleVector2PropertyEditor.GetName: shortstring;
begin
  Result := inherited GetName;
  { Since all such properties are called XxxPersistent, and they correspond
    to properties called just Xxx (TCastleVector2PropertyEditor corresponds
    to TVector2) so it's more readable to just hide the "persistent" suffix. }
  Result := SuffixRemove('persistent', Result, true);
end;

function TCastleVector2PropertyEditor.GetValue: String;
var
  VectorPersistent: TCastleVector2Persistent;
begin
  VectorPersistent := (GetObjectValue as TCastleVector2Persistent);
  Result := VectorPersistent.Value.ToString;
end;

procedure TCastleVector2PropertyEditor.SetAllValues(const NewValue: TVector2);
var
  I: Integer;
  VectorPersistent: TCastleVector2Persistent;
begin
  for I := 0 to PropCount - 1 do
  begin
    VectorPersistent := GetObjectValueAt(I) as TCastleVector2Persistent;
    VectorPersistent.Value := NewValue;
  end;
  Modified;
end;

procedure TCastleVector2PropertyEditor.SetValue(const NewValue: String);
begin
  SetAllValues(Vector2FromStr(NewValue));
end;

function TCastleVector2PropertyEditor.GetDefaultValue: String;
var
  VectorPersistent: TCastleVector2Persistent;
begin
  VectorPersistent := (GetObjectValue as TCastleVector2Persistent);
  Result := VectorPersistent.InternalDefaultValue.ToString;
end;

function TCastleVector2PropertyEditor.ValueIsStreamed: boolean;
var
  VectorPersistent: TCastleVector2Persistent;
begin
  VectorPersistent := (GetObjectValue as TCastleVector2Persistent);
  Result := not VectorPersistent.HasDefaultValue;
end;

function TCastleVector2PropertyEditor.AllEqual: Boolean;
var
  I: Integer;
  Value1, Value2: TVector2;
begin
  if PropCount > 1 then
  begin
    Value1 := (GetObjectValueAt(0) as TCastleVector2Persistent).Value;
    for I := 1 to PropCount - 1 do
    begin
      Value2 := (GetObjectValueAt(I) as TCastleVector2Persistent).Value;
      if not TVector2.PerfectlyEquals(Value1, Value2) then
        Exit(false);
    end;
  end;

  Result := true;
end;

{ TCastleVector3PropertyEditor ------------------------------------------------- }

type
  TCastleVector3PropertyEditor = class(TSubPropertiesEditor)
  strict protected
    procedure SetAllValues(const NewValue: TVector3);
  public
    function GetAttributes: TPropertyAttributes; override;
    function GetName: shortstring; override;
    function GetValue: String; override;
    procedure SetValue(const NewValue: String); override;
    function GetDefaultValue: String; override;
    function ValueIsStreamed: boolean; override;
    function AllEqual: Boolean; override;
  end;

function TCastleVector3PropertyEditor.GetAttributes: TPropertyAttributes;
begin
  Result := inherited GetAttributes + [paRevertable]
    // our SetValue allows to set value from string
    - [paReadOnly];
end;

function TCastleVector3PropertyEditor.GetName: shortstring;
begin
  Result := inherited GetName;
  { Since all such properties are called XxxPersistent, and they correspond
    to properties called just Xxx (TCastleVector3PropertyEditor corresponds
    to TVector3) so it's more readable to just hide the "persistent" suffix. }
  Result := SuffixRemove('persistent', Result, true);
end;

function TCastleVector3PropertyEditor.GetValue: String;
var
  VectorPersistent: TCastleVector3Persistent;
begin
  VectorPersistent := (GetObjectValue as TCastleVector3Persistent);
  Result := VectorPersistent.Value.ToString;
end;

procedure TCastleVector3PropertyEditor.SetAllValues(const NewValue: TVector3);
var
  I: Integer;
  VectorPersistent: TCastleVector3Persistent;
begin
  for I := 0 to PropCount - 1 do
  begin
    VectorPersistent := GetObjectValueAt(I) as TCastleVector3Persistent;
    VectorPersistent.Value := NewValue;
  end;
  Modified;
end;

procedure TCastleVector3PropertyEditor.SetValue(const NewValue: String);
begin
  SetAllValues(Vector3FromStr(NewValue));
end;

function TCastleVector3PropertyEditor.GetDefaultValue: String;
var
  VectorPersistent: TCastleVector3Persistent;
begin
  VectorPersistent := (GetObjectValue as TCastleVector3Persistent);
  Result := VectorPersistent.InternalDefaultValue.ToString;
end;

function TCastleVector3PropertyEditor.ValueIsStreamed: boolean;
var
  VectorPersistent: TCastleVector3Persistent;
begin
  VectorPersistent := (GetObjectValue as TCastleVector3Persistent);
  Result := not VectorPersistent.HasDefaultValue;
end;

function TCastleVector3PropertyEditor.AllEqual: Boolean;
var
  I: Integer;
  Value1, Value2: TVector3;
begin
  if PropCount > 1 then
  begin
    Value1 := (GetObjectValueAt(0) as TCastleVector3Persistent).Value;
    for I := 1 to PropCount - 1 do
    begin
      Value2 := (GetObjectValueAt(I) as TCastleVector3Persistent).Value;
      if not TVector3.PerfectlyEquals(Value1, Value2) then
        Exit(false);
    end;
  end;

  Result := true;
end;

{ TScalePropertyEditor ------------------------------------------------- }

type
  { Editor for TVector3 properties, that accepts also a single float as input
    -- the float is interpreted as if it was repeated 3x.
    E.g. "2" works the same as "2 2 2".

    This is nice for 3D size / scale properties,
    like TCastleTransform.Scale, TCastleBox.Size. }
  TScalePropertyEditor = class(TCastleVector3PropertyEditor)
    procedure SetValue(const NewValue: String); override;
  end;

procedure TScalePropertyEditor.SetValue(const NewValue: String);
var
  F: Single;
  V: TVector3;
begin
  try
    F := StrToFloat(NewValue);
    V := Vector3(F, F, F);
  except
    on EConvertError do
      V := Vector3FromStr(NewValue);
  end;
  SetAllValues(V);
end;

{ TSize2DPropertyEditor ------------------------------------------------- }

type
  { Editor for Size:TVector2 properties, like TCastlePlane.Size. }
  TSize2DPropertyEditor = class(TCastleVector2PropertyEditor)
    procedure SetValue(const NewValue: String); override;
  end;

procedure TSize2DPropertyEditor.SetValue(const NewValue: String);
var
  F: Single;
  V: TVector2;
begin
  try
    { accept just a single float as input, so e.g. "2" works the same as "2 2" }
    F := StrToFloat(NewValue);
    V := Vector2(F, F);
  except
    on EConvertError do
      V := Vector2FromStr(NewValue);
  end;
  SetAllValues(V);
end;

{ TCastleVector4PropertyEditor ------------------------------------------------- }

type
  TCastleVector4PropertyEditor = class(TSubPropertiesEditor)
  strict private
    procedure SetAllValues(const NewValue: TVector4);
  public
    function GetAttributes: TPropertyAttributes; override;
    function GetName: shortstring; override;
    function GetValue: String; override;
    procedure SetValue(const NewValue: String); override;
    function GetDefaultValue: String; override;
    function ValueIsStreamed: boolean; override;
    function AllEqual: Boolean; override;
  end;

function TCastleVector4PropertyEditor.GetAttributes: TPropertyAttributes;
begin
  Result := inherited GetAttributes + [paRevertable]
    // our SetValue allows to set value from string
    - [paReadOnly];
end;

function TCastleVector4PropertyEditor.GetName: shortstring;
begin
  Result := inherited GetName;
  Result := SuffixRemove('persistent', Result, true);
end;

function TCastleVector4PropertyEditor.GetValue: String;
var
  VectorPersistent: TCastleVector4Persistent;
begin
  VectorPersistent := (GetObjectValue as TCastleVector4Persistent);
  Result := VectorPersistent.Value.ToString;
end;

procedure TCastleVector4PropertyEditor.SetAllValues(const NewValue: TVector4);
var
  I: Integer;
  VectorPersistent: TCastleVector4Persistent;
begin
  for I := 0 to PropCount - 1 do
  begin
    VectorPersistent := GetObjectValueAt(I) as TCastleVector4Persistent;
    VectorPersistent.Value := NewValue;
  end;
  Modified;
end;

procedure TCastleVector4PropertyEditor.SetValue(const NewValue: String);
begin
  SetAllValues(Vector4FromStr(NewValue));
end;

function TCastleVector4PropertyEditor.GetDefaultValue: String;
var
  VectorPersistent: TCastleVector4Persistent;
begin
  VectorPersistent := (GetObjectValue as TCastleVector4Persistent);
  Result := VectorPersistent.InternalDefaultValue.ToString;
end;

function TCastleVector4PropertyEditor.ValueIsStreamed: boolean;
var
  VectorPersistent: TCastleVector4Persistent;
begin
  VectorPersistent := (GetObjectValue as TCastleVector4Persistent);
  Result := not VectorPersistent.HasDefaultValue;
end;

function TCastleVector4PropertyEditor.AllEqual: Boolean;
var
  I: Integer;
  Value1, Value2: TVector4;
begin
  if PropCount > 1 then
  begin
    Value1 := (GetObjectValueAt(0) as TCastleVector4Persistent).Value;
    for I := 1 to PropCount - 1 do
    begin
      Value2 := (GetObjectValueAt(I) as TCastleVector4Persistent).Value;
      if not TVector4.PerfectlyEquals(Value1, Value2) then
        Exit(false);
    end;
  end;

  Result := true;
end;
