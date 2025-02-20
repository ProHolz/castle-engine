{ -*- buffer-read-only: t -*-

  Copyright 2015-2023 Michalis Kamburelis.

  This file is part of "Castle Game Engine".

  "Castle Game Engine" is free software; see the file COPYING.txt,
  included in this distribution, for details about the copyright.

  "Castle Game Engine" is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

  ----------------------------------------------------------------------------
}

{ Automatically generated node properties.

  Do not edit this file manually!
  To add new properties:
  - add them to the text files in tools/internal/x3d-nodes-to-pascal/nodes-specification/ ,
  - and regenerate include files by running x3d-nodes-to-pascal }

{$ifdef read_interface}

  strict private
    function GetColor: TCastleColorRGB;
    procedure SetColor(const Value: TCastleColorRGB);
    function GetEnabled: Boolean;
    procedure SetEnabled(const Value: Boolean);
    function GetFogType: TFogType;
    procedure SetFogType(const Value: TFogType);
    function GetVisibilityRange: Single;
    procedure SetVisibilityRange(const Value: Single);
    function GetVolumetric: Boolean;
    procedure SetVolumetric(const Value: Boolean);
    function GetVolumetricDirection: TVector3;
    procedure SetVolumetricDirection(const Value: TVector3);
    function GetVolumetricVisibilityStart: Single;
    procedure SetVolumetricVisibilityStart(const Value: Single);
  public
    procedure CreateNode; override;
    class function ClassX3DType: string; override;

    strict private FFdColor: TSFColor;
    { Internal wrapper for property @link(Color). This wrapper API may change, we advise to access simpler @link(Color) instead. }
    public property FdColor: TSFColor read FFdColor;
    {  }
    property Color: TCastleColorRGB read GetColor write SetColor;

    strict private FFdEnabled: TSFBool;
    { Internal wrapper for property @link(Enabled). This wrapper API may change, we advise to access simpler @link(Enabled) instead. }
    public property FdEnabled: TSFBool read FFdEnabled;
    {  }
    property Enabled: Boolean read GetEnabled write SetEnabled;

    strict private FFdFogType: TSFStringEnum;
    { Internal wrapper for property @link(FogType). This wrapper API may change, we advise to access simpler @link(FogType) instead. }
    public property FdFogType: TSFStringEnum read FFdFogType;
    {  }
    property FogType: TFogType read GetFogType write SetFogType;

    strict private FFdVisibilityRange: TSFFloat;
    { Internal wrapper for property @link(VisibilityRange). This wrapper API may change, we advise to access simpler @link(VisibilityRange) instead. }
    public property FdVisibilityRange: TSFFloat read FFdVisibilityRange;
    {  }
    property VisibilityRange: Single read GetVisibilityRange write SetVisibilityRange;

    strict private FFdVolumetric: TSFBool;
    { Internal wrapper for property @link(Volumetric). This wrapper API may change, we advise to access simpler @link(Volumetric) instead. }
    public property FdVolumetric: TSFBool read FFdVolumetric;
    { Activate volumetric fog, see https://castle-engine.io/x3d_extensions.php }
    property Volumetric: Boolean read GetVolumetric write SetVolumetric;

    strict private FFdVolumetricDirection: TSFVec3f;
    { Internal wrapper for property @link(VolumetricDirection). This wrapper API may change, we advise to access simpler @link(VolumetricDirection) instead. }
    public property FdVolumetricDirection: TSFVec3f read FFdVolumetricDirection;
    {  }
    property VolumetricDirection: TVector3 read GetVolumetricDirection write SetVolumetricDirection;

    strict private FFdVolumetricVisibilityStart: TSFFloat;
    { Internal wrapper for property @link(VolumetricVisibilityStart). This wrapper API may change, we advise to access simpler @link(VolumetricVisibilityStart) instead. }
    public property FdVolumetricVisibilityStart: TSFFloat read FFdVolumetricVisibilityStart;
    {  }
    property VolumetricVisibilityStart: Single read GetVolumetricVisibilityStart write SetVolumetricVisibilityStart;

{$endif read_interface}

{$ifdef read_implementation}

{ TLocalFogNode ----------------------------------------------- }

function TLocalFogNode.GetColor: TCastleColorRGB;
begin
  Result := FdColor.Value;
end;

procedure TLocalFogNode.SetColor(const Value: TCastleColorRGB);
begin
  FdColor.Send(Value);
end;

function TLocalFogNode.GetEnabled: Boolean;
begin
  Result := FdEnabled.Value;
end;

procedure TLocalFogNode.SetEnabled(const Value: Boolean);
begin
  FdEnabled.Send(Value);
end;

function TLocalFogNode.GetFogType: TFogType;
begin
  Result := TFogType(FdFogType.EnumValue);
end;

procedure TLocalFogNode.SetFogType(const Value: TFogType);
begin
  FdFogType.SendEnumValue(Ord(Value));
end;

function TLocalFogNode.GetVisibilityRange: Single;
begin
  Result := FdVisibilityRange.Value;
end;

procedure TLocalFogNode.SetVisibilityRange(const Value: Single);
begin
  FdVisibilityRange.Send(Value);
end;

function TLocalFogNode.GetVolumetric: Boolean;
begin
  Result := FdVolumetric.Value;
end;

procedure TLocalFogNode.SetVolumetric(const Value: Boolean);
begin
  FdVolumetric.Send(Value);
end;

function TLocalFogNode.GetVolumetricDirection: TVector3;
begin
  Result := FdVolumetricDirection.Value;
end;

procedure TLocalFogNode.SetVolumetricDirection(const Value: TVector3);
begin
  FdVolumetricDirection.Send(Value);
end;

function TLocalFogNode.GetVolumetricVisibilityStart: Single;
begin
  Result := FdVolumetricVisibilityStart.Value;
end;

procedure TLocalFogNode.SetVolumetricVisibilityStart(const Value: Single);
begin
  FdVolumetricVisibilityStart.Send(Value);
end;

class function TLocalFogNode.ClassX3DType: String;
begin
  Result := 'LocalFog';
end;

procedure TLocalFogNode.CreateNode;
begin
  inherited;

  FFdColor := TSFColor.Create(Self, True, 'color', Vector3(1, 1, 1));
   FdColor.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdColor);

  FFdEnabled := TSFBool.Create(Self, True, 'enabled', true);
   FdEnabled.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdEnabled);

  FFdFogType := TSFStringEnum.Create(Self, True, 'fogType', @FogTypeNames, Ord(High(FogTypeNames)) + 1, Ord(ftLinear));
   FdFogType.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdFogType);

  FFdVisibilityRange := TSFFloat.Create(Self, True, 'visibilityRange', 0);
   FdVisibilityRange.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdVisibilityRange);

  FFdVolumetric := TSFBool.Create(Self, True, 'volumetric', false);
   FdVolumetric.ChangeAlways := chEverything;
  AddField(FFdVolumetric);

  FFdVolumetricDirection := TSFVec3f.Create(Self, True, 'volumetricDirection', Vector3(0, -1, 0));
   FdVolumetricDirection.ChangeAlways := chEverything;
  AddField(FFdVolumetricDirection);

  FFdVolumetricVisibilityStart := TSFFloat.Create(Self, True, 'volumetricVisibilityStart', 0);
   FdVolumetricVisibilityStart.ChangeAlways := chEverything;
  AddField(FFdVolumetricVisibilityStart);
end;

{$endif read_implementation}
