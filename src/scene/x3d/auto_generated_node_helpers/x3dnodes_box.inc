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
    function GetSize: TVector3;
    procedure SetSize(const Value: TVector3);
    function GetCcw: Boolean;
    procedure SetCcw(const Value: Boolean);
  public
    procedure CreateNode; override;
    class function ClassX3DType: string; override;

    strict private FFdSize: TSFVec3f;
    { Internal wrapper for property @link(Size). This wrapper API may change, we advise to access simpler @link(Size) instead. }
    public property FdSize: TSFVec3f read FFdSize;
    {  }
    property Size: TVector3 read GetSize write SetSize;

    strict private FFdSolid: TSFBool;
    { Internal wrapper for property @link(Solid). This wrapper API may change, we advise to access simpler @link(Solid) instead. }
    public property FdSolid: TSFBool read FFdSolid;

    strict private FFdCcw: TSFBool;
    { Internal wrapper for property @link(Ccw). This wrapper API may change, we advise to access simpler @link(Ccw) instead. }
    public property FdCcw: TSFBool read FFdCcw;
    {  }
    property Ccw: Boolean read GetCcw write SetCcw;

    strict private FFdTexCoord: TSFNode;
    { Internal wrapper for property @link(TexCoord). This wrapper API may change, we advise to access simpler @link(TexCoord) instead. }
    public property FdTexCoord: TSFNode read FFdTexCoord;

{$endif read_interface}

{$ifdef read_implementation}

{ TBoxNode ----------------------------------------------- }

function TBoxNode.GetSize: TVector3;
begin
  Result := FdSize.Value;
end;

procedure TBoxNode.SetSize(const Value: TVector3);
begin
  FdSize.Send(Value);
end;

function TBoxNode.GetCcw: Boolean;
begin
  Result := FdCcw.Value;
end;

procedure TBoxNode.SetCcw(const Value: Boolean);
begin
  FdCcw.Send(Value);
end;

class function TBoxNode.ClassX3DType: String;
begin
  Result := 'Box';
end;

procedure TBoxNode.CreateNode;
begin
  inherited;

  FFdSize := TSFVec3f.Create(Self, False, 'size', Vector3(2, 2, 2));
   FdSize.ChangeAlways := chGeometry;
  AddField(FFdSize);

  FFdSolid := TSFBool.Create(Self, False, 'solid', true);
   FdSolid.ChangeAlways := chGeometry;
  AddField(FFdSolid);

  FFdCcw := TSFBool.Create(Self, False, 'ccw', true);
   FdCcw.ChangeAlways := chGeometry;
  AddField(FFdCcw);

  FFdTexCoord := TSFNode.Create(Self, True, 'texCoord', [TTextureCoordinateGeneratorNode, TProjectedTextureCoordinateNode, TMultiGeneratedTextureCoordinateNode]);
   FdTexCoord.ChangeAlways := chGeometry;
  AddField(FFdTexCoord);
end;

{$endif read_implementation}
